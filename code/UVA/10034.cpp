/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-31 10:12:42 
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

struct __dot
{
	double x,y;
	double dis(const __dot &d)
	{
		return sqrt( sqr(x-d.x)+sqr(y-d.y));
	}
}dot[maxn];

double G[maxn][maxn];
double mincost[maxn];
bool vis[maxn];
int n;

double prim(int s=0)
{
	for (int i=0;i<n;i++)
		mincost[i]=INF;
	memset(vis,0,sizeof vis);
	mincost[s]=0;
	
	double res=0;
	
	for (;;)
	{
		int v=-1;
		
		for (int i=0;i<n;i++)
			if (!vis[i] && (v==-1 || mincost[v]>mincost[i]))
				v=i;
				
		if (v==-1)	break;
		
		res+=mincost[v];
		vis[v]=true;
		
		for (int i=0;i<n;i++)
		{
			mincost[i]=min(mincost[i],G[v][i]);
		}
		
	}
	
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf( "%lf%lf",&dot[i].x,&dot[i].y);
			for (int j=0;j<=i;j++)
			{
				G[i][j]=G[j][i]=dot[i].dis(dot[j]);
			}
		}
		
		printf( "%.2f\n",prim());
		
		if (T_T)	putchar( '\n');
	}
	
	return 0;
}



