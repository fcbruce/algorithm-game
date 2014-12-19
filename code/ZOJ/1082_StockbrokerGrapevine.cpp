/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 15:32:00 
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
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	
	while (scanf( "%d",&n),n)
	{
		memset(G,0x3f,sizeof G);
		for (int i=1;i<=n;i++)
		{
			G[i][i]=0;
			int k,obj,t;
			scanf( "%d",&k);
			for (int j=0;j<k;j++)
			{
				scanf( "%d%d",&obj,&t);
				G[i][obj]=t;
			}
		}
		
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
					
		int MIN=INF,the_one=-1;
		for (int i=1;i<=n;i++)
		{
			int MAX=0;
			for (int j=1;j<=n;j++)
			{
				if (G[i][j]==INF)
				{
					MAX=-1;
					break;
				}
				MAX=max(MAX,G[i][j]);
			}
			if (MAX!=-1)
			{
				if (MIN>MAX)
				{
					MIN=MAX;
					the_one=i;
				}
			}
		}
		
		if (~the_one)
			printf( "%d %d\n",the_one,MIN);
		else
			puts( "disjoint");
	}
	
	return 0;
}



