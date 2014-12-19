/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-04 19:46:55 
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
#define maxn 33

using namespace std;

int G[maxn][maxn];

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int n,m,T_T=0;
	
	while (~scanf( "%d",&m))
	{
		memset(G,0,sizeof G);
		n=0;
		
		for (int i=0,u,v;i<m;i++)
		{
			scanf( "%d%d",&u,&v);
			G[u][v]++;
			n=max(n,max(u,v));
		}
		
		n++;
		
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					G[i][j]+=G[i][k]*G[k][j];
				
		for (int k=0;k<n;k++)
			if (G[k][k])
				for (int i=0;i<n;i++)
					for (int j=0;j<n;j++)
						if (G[i][k] && G[k][j])
							G[i][j]=-1;
					
		printf( "matrix for city %d\n",T_T++);
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (j)	putchar( ' ');
				printf( "%d",G[i][j]);
			}
			putchar( '\n');
		}
	}
	
	return 0;
}



