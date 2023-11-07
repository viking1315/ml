#include <iostream>
using namespace std;

class item {
public:
    int p; // Profit of the item
    int w; // Weight of the item
};

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void bubblesort(item a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].w > a[j + 1].w) {
                item temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void knapsack(int n, int c, item a[]) {
    int maxprofit[n + 1][c + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0) {
                maxprofit[i][j] = 0;
            } else {
                maxprofit[i][j] = max(maxprofit[i - 1][j], maxprofit[i - 1][j - a[i - 1].w] + a[i - 1].p);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            cout << maxprofit[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, c;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity: ";
    cin >> c;
    
    item a[n];
    for (int i = 0; i < n; i++) {
        cout << "Weight of object " << i + 1 << " = ";
        cin >> a[i].w;
        cout << "Profit of object " << i + 1 << " = ";
        cin >> a[i].p;
    }
    
    bubblesort(a, n);
    knapsack(n, c, a);
    return 0;
}

