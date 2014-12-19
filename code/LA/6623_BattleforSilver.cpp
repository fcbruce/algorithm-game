/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-26 20:36:48 
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
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

#ifdef _WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 2333 
#define maxn 505

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
bool G[maxn][maxn];
int w[maxn];
int vis[maxn];
int st[4];
int top;
int res;
int pending[maxn],pt;

void add_edge(int _u,int _v)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int x,int save)
{
	vis[x]=1;
	res=max(res,save);
	printf( " %d %d\n",x,save);
	if (top==3)
	{
		vis[x]=0;
		return ;
	}
	
	for ()
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m;
	
	while (~scanf( "%d%d",&n,&m))
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		pt=-1;
		
		for (int i=1;i<=n;i++)
		{
			scanf( "%d",w+i);
			pendint[++pt=i;]
			add_edge(0,i);	
		}
			
		memset(G,0,sizeof G);
		
		for (int i=0,u,v;i<m;i++)
		{
			scanf( "%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			G[u][v]=G[v][u]=true;
		}
		
		memset(vis,1,sizeof vis);
		res=0;
		top=-1;
		dfs(0,0);
		
		printf( "%d\n",res);
	}
	
	return 0;
}



