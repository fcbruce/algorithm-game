/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-03 18:16:16 
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

#define maxm (50505<<1)
#define maxn 23333

using namespace std;

int n,m;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];
int q[maxm<<3];
bool inq[maxn];

inline void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
	memset(d,0x3f,sizeof d);
	memset(inq,0,sizeof inq);
	d[s]=0;
	int f,r;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[f++];
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
				}
			}
		}
	}
}

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int T_T,__=0;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		int s,t;
		scanf( "%d%d%d%d",&n,&m,&s,&t);
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		
		SPFA(s);
		
		printf( "Case #%d: ",++__);
		if (d[t]==INF)
			puts( "unreachable");
		else
			printf( "%d\n",d[t]);
	}
	
	return 0;
}



