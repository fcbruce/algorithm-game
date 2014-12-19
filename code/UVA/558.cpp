/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-03 19:33:07 
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

#define maxm 2333
#define maxn 1010

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int d[maxn],inc[maxn];
int q[maxm<<3];
bool inq[maxn];

inline void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

bool negative_loop()
{
	int f=0,r=-1;
	memset(d,0,sizeof d);
	memset(inq,1,sizeof inq);
	memset(inc,0,sizeof inc);
	for (int i=0;i<n;i++)
		q[++r]=i;
	
	while (f<=r)
	{
		int x=q[r--];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					q[++r]=v[e];
					if (++inc[v[e]]>n)	return true;
				}
			}
		}
	}
	
	return false;
}

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		scanf( "%d%d",&n,&m);
		
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
		}
		
		if (negative_loop())
			puts( "possible");
		else
			puts( "not possible");
	}
	
	return 0;
}



