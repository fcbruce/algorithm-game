/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-31 23:43:32 
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
	
	int n,m,q,__=0;
	
	while (scanf( "%d%d%d",&n,&m,&q),n||m||q)
	{
		if (__)	putchar( '\n');
		printf( "Case #%d\n",++__);
	
		memset(G,0x3f,sizeof G);
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			G[u][v]=G[v][u]=w;
		}
		
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
					
		for (int i=0,u,v;i<q;i++)
		{
			scanf( "%d%d",&u,&v);
			if (G[u][v]==INF)
				puts( "no path");
			else
				printf( "%d\n",G[u][v]);
		}
	}
	
	return 0;
}



