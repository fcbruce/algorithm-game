/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-04 10:40:50 
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
#define maxn 23

using namespace std;

int n;
double G[maxn][maxn][maxn];
int p[maxn][maxn][maxn];

void print(int u,int v,int t)
{
	if (t==0)
	{
		printf( "%d",u);
		return ;
	}
	
	print(u,p[u][v][t],t-1);
	printf( " %d",v);
}

bool floyd()
{
	for (int t=2;t<=n;t++)
	{
		for (int k=1;k<=n;k++)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (G[i][j][t]<G[i][k][t-1]*G[k][j][1])
					{
						G[i][j][t]=G[i][k][t-1]*G[k][j][1];
						p[i][j][t]=k;
					}
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (G[i][i][t]>1.01)
			{
				print(i,i,t);
				putchar( '\n');
				return true;
			}
		}	
	}
	
	return false;
	
}

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	while (~scanf( "%d",&n))
	{
		memset(G,0,sizeof G);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j)	continue;
				scanf( "%lf",&G[i][j][1]);
			}
		}
		
		if ( floyd())
		{
			;
		}
		else
		{
			puts( "no arbitrage sequence exists");
		}
	}
	
	return 0;
}



