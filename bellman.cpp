#include<iostream>
using namespace std;
class edge
{
	public:
		int src;
		int weight;
		int dest;
		int distance;
		
		void bellman(edge a[], int v, int e, int source);
};

void edge::bellman(edge a[], int v, int e, int source)
{
	int start;
	int end;
	for(int i=0;i<v;i++)
	{
		int flag=0;
		for(int j=0;j<e;j++)
		{
			start=a[j].src;
			end=a[j].dest;
			if(a[start].dest != 999 && (a[end].distance>a[start].distance + a[j].weight))
			{
				a[end].distance=a[start].distance+a[j].weight;
				flag=1;
			}
		}
		if(flag==0)
		break;
		cout<<"\niteration no."<<i+1<<"=\n";
		cout<<"vertex \t distance\n";				
		for(int i=0;i<v;i++) 
		{
			cout<<i+1<<"\t"<<a[i+1].distance<<"\n";
		}
	}
	cout<<"\n final shortest distance";
	for(int i=0;i<v;i++)
	{
		cout<<i+v<<"\t"<<a[i+1].distance<<"\n";
	}	
}
int main()
{
	int v,e,source;
	cout<<"enter the no. of vertices";
	cin>>v;
	cout<<"enter the no. of edges";
	cin>>e;
	cout<<"enter the source vertex";
	cin>>source;
	edge a[e];
	for(int i=0;i<v;i++)
	{
		cout<<"\n enter the source of edge";
		cin>>a[i].src;
		cout<<"\n enter the destination of edge";
		cin>>a[i].dest;
		cout<<"\n enter the weight of edge";
		cin>>a[i].weight;
	a[i].distance = 999;
	}
	cout<<"\n diaplaying table";
	cout<<"\n ID \t source \t destination \t weight \t distance \n";
	for(int i=0;i<v;i++)
	{
		cout<<i;
		cout<<a[i].src<<"\t"<<a[i].dest<<"\t"<<a[i].weight<<"t"<<a[i].distance<<"\t";
	}
	edge obj;
	obj.bellman(a,v,e,source);
}
