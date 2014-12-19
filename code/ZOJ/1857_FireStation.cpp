/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 16:26:16 
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
#define maxn 

using namespace std;

int fs[101];
int nearest[555];
int G[555][555];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int f,n;
	
	while (~scanf( "%d %d",&f,&n))
	{
		for (int i=0;i<f;i++)
			scanf( "%d",fs+i);
			
		getchar();
	
		memset(G,0x3f,sizeof G);
		for (int i=1;i<=n;i++)	G[i][i]=0;
	
		char sstr[23];	
		for (;;)
		{
			memset(sstr,0,sizeof sstr);
			fgets(sstr,23,stdin);
//			puts(sstr);
			int u,v,w;
			if (sstr[0]!='\n' && sstr[0])
			{
				sscanf(sstr, "%d%d%d",&u,&v,&w);
//				printf( "%d %d %d\n",u,v,w);
				G[u][v]=G[v][u]=w;
			}
			else
				break;
			
		}
		
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
					
		memset(nearest,INF,sizeof nearest);
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<f;j++)
			{
				nearest[i]=min(nearest[i],min(G[i][fs[j]],G[fs[j]][i]));
			}
		}
		
//		for (int i=1;i<=n;i++)
//			printf( "%d ",nearest[i]);
//			
//		putchar( '\n');
		
		int MAX_id=1;
		for (int i=2;i<=n;i++)
		{
			if (nearest[MAX_id]<nearest[i])
				MAX_id=i;
		}
		
		printf( "%d\n",MAX_id);
		
//		for (int i=1;i<=n;i++)
//		{
//			if (G[i][MAX_id]<nearest[MAX_id] || G[MAX_id][i]<nearest[MAX_id])
//			{
//				printf( "%d\n",i);
//				break;
//			}
//		}
	}
	
	
	return 0;
}



