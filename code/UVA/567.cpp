/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 15:58:58 
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
#define maxn 22

using namespace std;

int G[maxn][maxn];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,T_T=0;
	
	while ( ~scanf( "%d",&n))
	{
		printf( "Test Set #%d\n",++T_T);
		memset(G,0x3f,sizeof G);
		
		G[1][1]=0;
		for (int j=0,v;j<n;j++)
		{
			scanf( "%d",&v);
			G[1][v]=G[v][1]=1;
		}
		
		for (int i=2,v;i<=19;i++)
		{
			G[i][i]=0;
			scanf( "%d",&n);
			for (int j=0;j<n;j++)
			{
				scanf( "%d",&v);
				G[i][v]=G[v][i]=1;
			}
		}
		
		for (int k=1;k<=20;k++)
			for (int i=1;i<=20;i++)
				for (int j=1;j<=20;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		
		scanf( "%d",&n);
		for (int i=0,s,t;i<n;i++)
		{renre
			scanf( "%d%d",&s,&t);
			printf( "%2d to %2d: %d\n",s,t,G[s][t]);
		}
		
		putchar( '\n');
	}
	
	return 0;
}



