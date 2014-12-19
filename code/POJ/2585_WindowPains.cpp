/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	
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
#define maxm 400
#define maxn 20

using namespace std;

int cov[16][5]={{1},{1,2},{2,3},{3},{1,4},{1,2,4,5},{2,3,4,5},{3,6},{4,7},{4,5,7,8},{5,6,8,9},{6,9},{7},{7,8},{8,9},{9}};

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
int deg[maxn];
int st[maxn];

void add_edge(int _u,int _v)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void build_add_edge(int i,int j,int x)
{
	int id=i*4+j,k=0;
	while (cov[id][k]!=0)
	{
		if (cov[id][k]!=x)
		{
			add_edge(x,cov[id][k]);
			deg[cov[id][k]]++;
		}
		k++;
	}
}

bool topo_sort()
{
	int top=-1;
	for (int i=1;i<10;i++)
	{
		if (deg[i]==0)
		{
			st[++top]=i;
		}
	}
	
	for (int i=0;i<9;i++)
	{
		if (top==-1)	return false;
		
		itn _u=st[top--];
		for (int e=fir[_u];~e;e=nex[e])
		{
			deg[v[e]]--;
			if (!deg[v[e]])
			{
				st[++top]=v[e];
			}
		}
	}
	
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int x;
	
	char str[123];
	
	while (~scanf("%s",str),strcmp(str,"ENDOFINPUT"))
	{
		memset(fir,-1,sizeof fir);
		memset(deg,0,sizeof deg);
		e_max=0;
		for (itn i=0;i<4;i++)
		{
			for (itn j=0;j<4;j++)
			{
				scanf( "%d",&x);
				build_add_edge(i,j,x);
			}
		}
		
		if (topo_sort())
		{
			puts( "THESE WINDOWS ARE CLEAN");
		}
		else
		{
			puts( "THESE WINDOWS ARE BROKEN");
		}
		
		scanf( "%s",str);
	}
	
	return 0;
}



