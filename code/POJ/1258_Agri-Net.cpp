/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 14:27:40 
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
#define maxm 
#define maxn 101

using namespace std;

int G[maxn][maxn];
int mincost[maxn];
bool vis[maxn];
int n;

int prim()
{
	memset(mincost,0x3f,sizeof mincost);
	memset(vis,0,sizeof vis);
	mincost[0]=0;
	int res=0;
	
	for (;;)
	{
		int v=-1;
		
		for (itn i=0;i<n;i++)
			if (!vis[i] && (v==-1 || mincost[v]>mincost[i]))	v=i;
			
		if (v==-1)	break;
		
		res+=mincost[v];
		vis[v]=true;
		
		for (int i=0;i<n;i++)
			mincost[i]=min(mincost[i],G[v][i]);
	}
	
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	while (~scanf( "%d",&n))
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				scanf( "%d",&G[i][j]);
				
		printf( "%d\n",prim());
	}
	
	return 0;
}



