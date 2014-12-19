/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-18 08:01:12 
 *
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 10010
#define maxn 233

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
double w[maxm],d[maxn];
int e_max;
bool inq[maxn];
int q[maxm<<3];

double x[20],y[20][8];


struct Point
{
	double x,y;
	Point operator + (Point p)
	{
		return (Point){x+p.x,y+p.y};
	}
	Point operator - (Point p)
	{
		return (Point){x-p.x,y-p.y};
	}
	double det(Point p)
	{
		return x*p.y-y*p.x;
	}
	double dot(Point p)
	{
		return x*p.x+y*p.y;
	}
};

void add_edge(Point p1,int i1,int j1,Point p2,int i2,int j2)
{
	
	int e=e_max++;
	u[e]=i1*5+j1;
	v[e]=i2*5+j2;
	w[e]=sqrt( (p1-p2).dot(p1-p2));
	nex[e]=fir[u[e]];fir[u[e]]=e;
//	printf( "%d --> %d  %.2f\n",u[e],v[e],w[e]);
}

bool check(Point p1,int s,Point p2,int t)
{
	for (int i=s;i<t;i++)
	{
		for (int j=0;j<5;j+=2)
		{
			if ( (p1-p2).det( (Point){x[i],y[i][j]}-p1)*(p1-p2).det( (Point){x[i],y[i][j+1]}-p1)<-eps)
				return false;
		}
	}
	
	return true;
}

void build(double _x,double _y,int n,int h)
{
	if (check( (Point){0,5},-1,(Point){_x,_y},n))
		add_edge( (Point){0,5},0,0,(Point){_x,_y},n,h);

	for (int i=0;i<n;i++)
	{
		for (int j=1;j<5;j++)
		{
			if (check( (Point){x[i],y[i][j]},i,(Point){_x,_y},n))
				add_edge(Point{x[i],y[i][j]},i,j,(Point){_x,_y},n,h);
		}
	}
}

void SPFA(int s)
{
	int f,r;
	for (int i=0;i<maxn;i++)	d[i]=INF;
	memset(inq,0,sizeof inq);
	d[s]=0;
	q[f=r=0]=s;
	
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e]+eps)
			{
				d[v[e]]=d[u[e]]+w[e];
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					q[++r]=v[e];
				}
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	
	while (scanf( "%d",&n),n!=-1)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		for (int i=0;i<n;i++)
		{
			scanf( "%lf",x+i);
			for (int j=1;j<=4;j++)
				scanf( "%lf",&y[i][j]);
			y[i][0]=0;
			y[i][5]=10;
		}
		
		for (int i=0;i<n;i++)
			for (int j=1;j<5;j++)
				build(x[i],y[i][j],i,j);
		
		build(10,5,n,1);
			
		SPFA(0);
		
		printf( "%.2f\n",d[n*5+1]);
	}	
	
	return 0;
}



