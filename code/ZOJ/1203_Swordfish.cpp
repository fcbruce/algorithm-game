/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 09:33:07 
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
#define maxm 10010
#define maxn 101

using namespace std;

struct __city
{
	double x,y;
}city[maxn];

struct __edge
{
	int u,v;
	double w;
	bool operator < (const __edge &e)const
	{
		return w<e.w;
	}
}edge[maxm];
int e_max;
int pre[maxn];

int root(int x)
{
	if (pre[x]==x)	return x;
	return pre[x]=root(pre[x]);
}

bool __same(int x,int y)
{
	return root(x)==root(y);
}

void __merge(int x,int y)
{
	pre[root(x)]=root(y);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,T_T=0;
	while (scanf( "%d",&n),n)
	{
		e_max=0;
		for (int i=0;i<n;i++)
		{
			scanf( "%lf %lf",&city[i].x,&city[i].y);
			for (int j=0;j<i;j++)
			{
				edge[e_max++]=(__edge){i,j,sqrt(sqr(city[i].x-city[j].x)+sqr(city[i].y-city[j].y))};
			}
		}
		
		sort(edge,edge+e_max);
		
		for (int i=0;i<n;i++) pre[i]=i;
		double res=0;
		
		for (int i=0;i<e_max;i++)
		{
			if (!__same(edge[i].u,edge[i].v))
			{
				__merge(edge[i].u,edge[i].v);
				n--;
				res+=edge[i].w;
				
				if (n==1)	break;
			}
		}
		
		if (T_T) putchar( '\n');
		printf( "Case #%d:\n",++T_T);
		printf( "The minimal distance is: %.2f\n",res);
	}
	
	return 0;
}



