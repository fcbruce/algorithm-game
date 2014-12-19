/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-01 23:15:20 
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

#define maxm sqr(757)
#define maxn 757

using namespace std;

struct __city
{
	int x,y;
	double dis(const __city &c)const
	{
		return sqrt(sqr(x-c.x)+sqr(y-c.y));
	}
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

inline void add_edge(int _u,int _v,double _w)
{
	edge[e_max++]=(__edge){_u,_v,_w};
}

int root(int x)
{
	if (x==pre[x])	return x;
	return pre[x]=root(pre[x]);
}

bool same(int u,int v)
{
	return root(u)==root(v);
}

void __merge(int u,int v)
{
	pre[root(u)]=root(v);
}

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int n,m,cnt;
	while (~scanf( "%d",&n))
	{
		e_max=0;
		for (int i=1;i<=n;i++)
		{
			scanf( "%d%d",&city[i].x,&city[i].y);
			for (int j=1;j<i;j++)
			{
				add_edge(i,j,city[i].dis(city[j]));
			}
		}
		
		for (int i=1;i<=n;i++)	pre[i]=i;
		cnt=n;
		
		scanf( "%d",&m);
		for (int i=0,u,v;i<m;i++)
		{
			scanf( "%d%d",&u,&v);
			if (same(u,v))continue;
			__merge(u,v);
			--cnt;
		}
		
		sort(edge,edge+e_max);
		
		double res=0;
		for (int i=0,u,v;i<e_max && cnt>1;i++)
		{
			u=edge[i].u;
			v=edge[i].v;
			if (same(u,v))continue;
			__merge(u,v);
			res+=edge[i].w;
			--cnt;
		}
		
		printf( "%.2f\n",res);
	}
	
	return 0;
}



