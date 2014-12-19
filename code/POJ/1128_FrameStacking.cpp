/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	2014-08-10 09:39:26 
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
#define maxm 
#define maxn 

using namespace std;

int h,w,n;
int L[30],R[30],U[30],D[30];
char MAP[33][33];
int fir[33][33];
int rec[33][33][30];
bool G[33][33];
int deg[33];
int topo[33];
bool pending[33];

void add_edge(int x,int y,int v)
{
	for (int i=0;i<fir[x][y];i++)
		if (rec[x][y][i]!=v && !G[rec[x][y][i]][v])
		{
			G[rec[x][y][i]][v]=true;
			deg[v]++;
		}
		
}

void init()
{
	memset(L,-1,sizeof L);
	memset(R,-1,sizeof R);
	memset(U,-1,sizeof U);
	memset(D,-1,sizeof D);
	
	for (int i=0;i<h;i++)
	{
		for (int j=0;j<w;j++)
		{
			if (isalpha(MAP[i][j]) && U[MAP[i][j]-'A']==-1)
				U[MAP[i][j]-'A']=i;
		}
	}
	
	for (int i=h-1;i>=0;i--)
	{
		for (int j=0;j<w;j++)
		{
			if (isalpha(MAP[i][j]) && D[MAP[i][j]-'A']==-1)
				D[MAP[i][j]-'A']=i;
		}
	}
	
	for (int i=0;i<w;i++)
	{
		for (int j=0;j<h;j++)
		{
			if (isalpha(MAP[j][i]) && L[MAP[j][i]-'A']==-1)
				L[MAP[j][i]-'A']=i;
		}
	}
	
	for (int i=w-1;i>=0;i--)
	{
		for (int j=0;j<h;j++)
		{
			if (isalpha(MAP[j][i]) && R[MAP[j][i]-'A']==-1)
				R[MAP[j][i]-'A']=i;
		}
	}
}

void build()
{
	memset(fir,0,sizeof fir);
	
	for (int i=0;;i++)
	{
		n=i;
		if (L[i]==-1)	break;
		
		for (int j=L[i];j<=R[i];j++)
		{
			rec[U[i]][j][fir[U[i]][j]++]=i;
			rec[D[i]][j][fir[D[i]][j]++]=i;
		}
		
		for (int j=U[i]+1;j<D[i];j++)
		{
			rec[j][L[i]][fir[j][L[i]]++]=i;
			rec[j][R[i]][fir[j][R[i]]++]=i;
		}
	}
	
	memset(G,0,sizeof G);
	memset(deg,0,sizeof deg);
	
	for (int i=0;i<h;i++)
	{
		for (int j=0;j<w;j++)
		{
			add_edge(i,j,MAP[i][j]-'A');
		}
	}
}

int st[33];

void write()
{
	for (int i=0;i<n;i++)
		putchar( st[i]+'A');
	putchar ( '\n');
}

void toposort(int x,int top)
{
	st[++top]=x;
	if (top==n-1)
	{
		write();
		return ;
	}
	
	for (int i=0;i<n;i++)
	{
		if (G[x][i])
		{
			deg[i]--;
			if (deg[i]==0)	pending[i]=true;
		}
	}
	
	for (int i=0;i<n;i++)
	{
		if (pending[i])
		{
			pending[i]=false;
			toposort(i,top);
			pending[i]=true;
		}
	}
	
	for (int i=0;i<n;i++)
	{
		if (G[x][i])
		{
			deg[i]++;
			if (deg[i]!=0)	pending[i]=false;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	
	while (~scanf ( "%d%d",&h,&w))
	{
		for (int i=0;i<h;i++)
		{
			scanf( "%s",MAP[i]);
		}
		
		init();
		
		build();
		
		memset(pending,0,sizeof pending);
		
		for (int i=0;i<n;i++)
		{
			if (deg[i]==0)
			{
				pending[i]=true;
			}
		}
		
		for (int i=0;i<n;i++)
		{
			if (pending[i])
			{
				pending[i]=false;
				toposort(i,-1);
				pending[i]=true;
			}
		}
	}
	
	return 0;
}



