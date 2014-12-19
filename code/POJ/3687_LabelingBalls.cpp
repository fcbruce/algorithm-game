/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	2014-08-11 09:02:51 
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
#define maxm 40004
#define maxn 202

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
int topo[maxn],deg[maxn];
int n,m;

void add_edge(int _u,int _v)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

bool toposort()
{
	priority_queue<int> q;
	for (int i=1;i<=n;i++)
		if (!deg[i])	q.push(i);
	
	for (int i=0;i<n;i++)
	{
		if (q.empty())	return false;
		
		int x=q.top();q.pop();
		
		topo[x]=n-i;
		
		for (int e=fir[x];~e;e=nex[e])
		{
			if (--deg[v[e]]==0)
				q.push(v[e]);
		}
	}
	
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf ( "%d",&T_T);
	
	while (T_T--)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		memset(deg,0,sizeof deg);
		
		scanf( "%d %d",&n,&m);
		
		for (int i=0,_u,_v;i<m;i++)
		{
			scanf( "%d %d",&_u,&_v);
			add_edge(_v,_u);
			deg[_u]++;
		}
		
		if (toposort())
		{
			for (int i=1;i<=n;i++)
			{
				printf( "%d",topo[i]);
				putchar(i!=n?' ':'\n');
			}
		}
		else
		{
			printf( "-1\n");
		}
	}
	
	return 0;
}



