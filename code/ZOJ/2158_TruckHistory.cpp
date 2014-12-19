/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 13:59:52 
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
#define maxm 4000004
#define maxn 2002

using namespace std;

char truck[maxn][8];
int n;
int mincost[maxn];
bool vis[maxn];

inline int dis(const char *s1,const char *s2)
{
	int diff=0;
	for (int i=0;i<7;i++)
		if (s1[i]!=s2[i])	diff++;
	return diff;
}

int prim()
{
	memset(mincost,0x3f,sizeof mincost);
	memset(vis,0,sizeof vis);
	mincost[0]=0;
	int res=0;
	
	for (;;)
	{
		int v=-1;
		for (int i=0;i<n;i++)
			if (!vis[i] && (v==-1 || mincost[v]>mincost[i]))	v=i;
			
		if (v==-1)	break;
		
		res+=mincost[v];
		vis[v]=true;
		
		for (int i=0;i<n;i++)
			mincost[i]=min(mincost[i],dis(truck[v],truck[i]));
	}
	
	return res;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	while (scanf( "%d",&n),n)
	{
		for (int i=0;i<n;i++)
			scanf( "%s",truck[i]);
		
		
		printf( "The highest possible quality is 1/%d.\n",prim());
	}
	
	return 0;
}



