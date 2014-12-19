/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-07 09:39:12 
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

#define maxm 
#define maxn 121

using namespace std;

int n,m;
int G[maxn][maxn];
bool vis[maxn][maxn];


int dfs(int total,int cur,int u,int t)
{
	if (u==t)	return 0;
	
	int num=0;
	
	for (int i=0;i<n;i++)
	{
		if (G[u][i]==1 && !vis[u][i] && cur+G[u][i]+G[i][t]==total)
		{
			num++;
			vis[u][i]=vis[i][u]=true;
			num+=dfs(total,cur+1,i,t);
		}
	}
	
	return num;
}
int main()
{
#ifdef FCBRUCE
	freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
	
	int T_T,__=0;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d%d",&n,&m);
		memset(G,0x3f,sizeof G);
		
		for (int i=0,u,v;i<m;i++)
		{
			scanf( "%d%d",&u,&v);
			G[u][v]=G[v][u]=1;
		}
		
		for (int i=0;i<n;i++)
			G[i][i]=0;
			
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
					
		
		int MAX=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				memset(vis,0,sizeof vis);
				
				int temp=dfs(G[i][j],0,i,j);
				
				MAX=max(MAX,temp);
			}
			
		printf( "Case #%d: %d\n",++__,MAX);
	}
	
	return 0;
}



