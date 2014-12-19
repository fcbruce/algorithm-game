/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 20:52:01 
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

#define maxm 233
#define maxn 233

using namespace std;

int n;
int _time[maxn];
int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max=0;
int d[maxn],inc[maxn];
int st[maxm<<3];
bool inq[maxn];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

bool SPFA(int s)
{
	memset(d,0x3f,sizeof d);
	memset(inq,0,sizeof inq);
	memset(inc,0,sizeof inc);
	int top=-1;
	d[s]=0;
	st[++top]=s;
	while (top>-1)
	{
		int x=st[top--];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					st[++top]=v[e];
					if (++inc[v[e]]>n)	return false;
				}
			}
		}
	}
	
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T=0;
	
	while (scanf( "%d",&n),n)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		for (int i=1,t;i<=n;i++)
		{
			scanf( "%d",_time+i);
			add_edge(0,i,-_time[i]);
		}
		
		char str[23];
		while (scanf( "%s",str),strcmp(str,"#"))
		{
			int u,v;
			scanf( "%d %d",&u,&v);
			
			if (strcmp(str,"FAS")==0)
			{
				add_edge(u,v,_time[u]);
				continue;
			}
			
			if (strcmp(str,"FAF")==0)
			{
				add_edge(u,v,_time[u]-_time[v]);
				continue;
			}
			
			if (strcmp(str,"SAF")==0)
			{
				add_edge(u,v,-_time[v]);
				continue;
			}
			
			if (strcmp(str,"SAS")==0)
			{
				add_edge(u,v,0);
				continue;
			}
		}
		
		printf( "Case %d:\n",++T_T);
		
		if (SPFA(0))
		{
			int plus=0;
			for (int i=1;i<=n;i++)
				plus=min(plus,d[i]);
			for (int i=1;i<=n;i++)
				printf( "%d %d\n",i,d[i]-plus);
		}
		else
			puts( "impossible");
			
		putchar( '\n');
	}
	
	return 0;
}



