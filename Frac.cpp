#include<iostream>
using namespace std;

class item
{
public:
int w;
int p;
};

int max(int a,int b)
{
if(a>b)
return a;
else
return b;
}

void bubblesort(item a[],int n)
{
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(a[j].w>a[j+1].w)
{
item temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;
}
}
}
}

void knapsack(int n,int c,item a[])
{
int maxprofit[n+1][c+1];

for(int i=0;i<n+1;i++)
{
for(int j=0;j<c+1;j++)
{
if(i==0 || j==0)
maxprofit[i][j]=0;
else
//not taking item        //taking item
maxprofit[i][j] = max(maxprofit[i-1][j], (maxprofit[i-1][j-a[i-1].w]+a[i-1].p));
}
}

for(int i=0;i<n+1;i++)
{
for(int j=0;j<c+1;j++)
{
cout<<maxprofit[i][j]<<" ";
}
cout<<endl;
}
} 

int main()
{
int n;
cout<<"enter no. of items in knapsack =";
cin>>n;

int c;
cout<<"enter capacity of knapsack=";
cin>>c;

item a[n];
for(int i=0;i<n;i++)
{
cout<<"enter weight of object"<<i+1<<"="<<endl;
cin>>a[i].w;
cout<<"enter profit of object"<<i+1<<"="<<endl;
cin>>a[i].p;
}
bubblesort(a,n);

knapsack(n,c,a);
return 0;

}
