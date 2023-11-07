#include<iostream>
using namespace std;
int issafe(int queen[][10], int row, int col, int n){
	for(int i=0;i<n;i+_){
		if(queen[i][col]==1){
			return 0;
		}
	}	
	for( int i=row,j=col ; i>=0&&j>=0;i--,j--){
		if(queen[i][j]==1){
			return 0;
		}
	}	
	for(int i=row,j=col ; i>=0&&j<n;i--,j++)	{
		if(queen[i][j]==1)	{
			return 0;
		}
	}
	return 1;
}
int placequeen(int queen[][10],int n, int row){
	if(n==row)	{
		for(int i=0;i<n;i++)	{
			for(int j=0;j<n;j++)	{
				cout<<queen[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
		return 1;	
	}
	int flag=0;
	for(int i=0;i<n;i++){
		if(issafe(queen,row,i,n)==1)	{
			queen[row][i]=1;
			flag=placequeen(queen,n,row+1) || flag;
			queen[row][i]=0;
		}
	}
	return flag;
}
int main()	{
	int n;
	cout<<"no. of queen";
	cin>>n;
	int queen[10][10]={0};
	if(placequeen(queen,n,0)==1)	{
		cout<<"solution exist";
	}
	else
	cout<<"sol.doesnt exist";
	cout<<"\n";
	return 0;
}

