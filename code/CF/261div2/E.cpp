/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	
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
#define maxm 333333
#define maxn 333333

using namespace std;

struct edge{
	int u,v,w;
	bool operator < (const edge &e)const
	{
		return w<e.w;
	}
}ee[maxm];

int len[maxm],mx[maxm];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m,_u,_v,_w;

	
	scanf( "%d %d",&n,&m);
	
	for (int i=0;i<m;i++)
	{
		scanf( "%d %d %d",&_u,&_v,&_w);
		ee[i]=(edge){_u,_v,_w};
	}
	
	memset(len,0,sizeof len);
	memset(mx,0,sizeof mx);
	
	sort(ee,ee+m);
	
	int ans=0;
	
	for (int i=0;i<m;i++)
	{
		if (mx[ee[i].u]<ee[i].w && len[ee[i].v]<len[ee[i].u]+1)
		{
			mx[ee[i].v]=ee[i].w;
			len[ee[i].v]=len[ee[i].u]+1;
			ans=max(len[ee[i].v],ans);
		}
	}
	
	printf ( "%d\n",ans);
	
	
	
	
	
	
	return 0;
}



