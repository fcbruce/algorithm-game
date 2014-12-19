/*
 *
 *	Author	:	fcbruce
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
#define maxm 6666
#define maxn 6666

using namespace std;

int fir[maxn],rate[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
int in[maxn];
int dp[maxn][2];

void add_edge(int _u,int _v)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;
	nex[e]=fir[u[e]];fir[u[e]]=e;
	in[_v]++;
}

void dfs(int s)
{
	dp[s][1]=rate[s];
	dp[s][0]=0;
	for (int e=fir[s];~e;e=nex[e])
	{
		dfs(v[e]);
		dp[s][1]+=dp[v[e]][0];
		dp[s][0]+=max(dp[v[e]][1],dp[v[e]][0]);
	}
		
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	
	while (~scanf( "%d",&n))
	{
		rate[0]=0;
		for (int i=1;i<=n;i++)
		{
			scanf( "%d",rate+i);
		}
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		memset(in,0,sizeof in);
		
		int _u,_v;
		while (scanf( "%d %d",&_u,&_v),_u||_v)
			add_edge(_v,_u);
			
		int root=0;
		for (int i=1;i<=n;i++)
			if (in[i]==0)
				add_edge(root,i);
			
		dfs(root);
		
		printf( "%d\n",max(dp[root][0],dp[root][1]));
		
	}
	
	return 0;
}



