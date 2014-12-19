/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-02 12:33:22 
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
#define maxn 101

using namespace std;

int G[maxn][maxn];

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int n,m,T_T=0;
	while (scanf( "%d%d",&n,&m),n||m)
	{
		memset(G,0,sizeof G);
		for (int i=1,u,v,w;i<=m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			G[u][v]=G[v][u]=w;
		}
		
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					G[i][j]=max(G[i][j],min(G[i][k],G[k][j]));
					
		int s,t,p;
		
		scanf( "%d%d%d",&s,&t,&p);
		
		
		int res=ceil((double)p/(G[s][t]-1));
		
		printf( "Scenario #%d\n",++T_T);
		printf( "Minimum Number of Trips = %d\n\n",res);
			
	}
	
	return 0;
}



