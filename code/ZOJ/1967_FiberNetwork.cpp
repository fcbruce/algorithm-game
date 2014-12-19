/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 14:31:09 
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
#define maxn 233

using namespace std;

unsigned int G[maxn][maxn];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	
	while (scanf( "%d",&n),n)
	{
		int u,v;
		char com[30];
		memset(G,0,sizeof G);
		while (scanf( "%d%d",&u,&v),u||v)
		{
			scanf( "%s",com);
			for (int i=0;com[i];i++)
			{
				G[u][v]|=1<<com[i]-'a';
			}
		}
		for (int i=1;i<=n;i++)
			G[i][i]=~0;
		
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					G[i][j]|=G[i][k]&G[k][j];
		
		while (scanf( "%d%d",&u,&v),u||v)
		{
			if (G[u][v]==0)
				putchar( '-');
			else
			{
				for (int i=0;i<=26;i++)
				{
					if (G[u][v]&1<<i)
					{
						putchar( 'a'+i);
					}		
				}
			}
			putchar( '\n');
			
		}
		
		putchar( '\n');
	}
	
	return 0;
}



