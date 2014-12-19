/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 20:34:03 
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

#define maxm 5555
#define maxn 101

using namespace std;

struct __edge
{
	int u,v,w;
	bool operator < (const __edge &e)const
	{
		return w<e.w;
	}
}edge[maxm];

int pre[maxn];

itn root(int x)
{
	if (x==pre[x])	return x;
	return pre[x]=root(pre[x]);
}

int same(int u,int v)
{
	return root(u)==root(v);
}

void __merge(int u,int v)
{
	pre[root(u)]=root(v);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m;
	
	while (scanf( "%d%d",&n,&m),n||m)
	{
		for (int i=0;i<m;i++)
			scanf( "%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			
		sort(edge,edge+m);
		
		int MIN=INF;
		
		for (int i=0;i<m;i++)
		{
			for (int j=1;j<=n;j++)	pre[j]=j;
			int last=-1,cnt=n;
			for (int j=i;j<m;j++)
			{
				if (same(edge[j].u,edge[j].v))	continue;

				cnt--;
				__merge(edge[j].u,edge[j].v);
				if (cnt==1)
				{
					last=edge[j].w;
					break;
				}
			}
			
			if (~last)	MIN=min(MIN,last-edge[i].w);
		}
		
		printf( "%d\n",MIN!=INF?MIN:-1);
	}
	
	return 0;
}



