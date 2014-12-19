/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-04 10:17:57 
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

#define maxm 111
#define maxn 111

using namespace std;

int n;
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn],inc[maxn];
int q[maxn];
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
	memset(inc,0,sizeof inc);
	memset(inq,1,sizeof inq);
	memset(d,0,sizeof d);
	for (int i=0;i<=n;i++)
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
	
	while (scanf( "%d",&n),n)
	{
		int m;
		scanf( "%d",&m);
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=0;i<m;i++)
		{
			int a,b,k;
			char ch;
			scanf( "%d %d %ct %d",&a,&b,&ch,&k);
			if (ch=='g')
				add_edge(a+b,a-1,-k-1);
			else
				add_edge(a-1,a+b,k-1);
		}
		
		if (negative_loop())
			puts( "successful conspiracy");
		else
			puts( "lamentable kingdom");
	}
	
	return 0;
}



