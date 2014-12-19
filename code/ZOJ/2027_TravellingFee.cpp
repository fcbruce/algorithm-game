/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 14:49:21 
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

map<string,int> MAP;
int cnt;

char u_str[20],v_str[20];

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int d[maxn],MAX[maxn];
int q[maxm<<3];
bool inq[maxn];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
	int f,r;
	memset(d,0x3f,sizeof d);
	memset(MAX,0,sizeof MAX);
	memset(inq,0,sizeof inq);
	d[s]=0;
	q[f=r=0]=s;
	
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (MAX[u[e]]<w[e])
			{
				if (d[v[e]]>d[u[e]]+MAX[u[e]])
				{
					d[v[e]]=d[u[e]]+MAX[u[e]];
					MAX[v[e]]=w[e];
					if (!inq[v[e]])
					{
						inq[v[e]]=true;
						q[++r]=v[e];
					}
				}
			}
			else
			{
				if (d[v[e]]>d[u[e]]+w[e])
				{
					d[v[e]]=d[u[e]]+w[e];
					MAX[v[e]]=MAX[u[e]];
					if (!inq[v[e]])
					{
						inq[v[e]]=true;
						q[++r]=v[e];
					}
				}
			}
		}
		
	}
	
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	while ( scanf( "%s%s",u_str,v_str)!=EOF)
	{
		MAP.clear();cnt=0;
		int s,t;
		s=MAP[string(u_str)]=++cnt;
		t=MAP[string(v_str)]=++cnt;
		
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		int n;
		scanf( "%d",&n);
		for (int i=0,_w;i<n;i++)
		{
			scanf( "%s%s%d",u_str,v_str,&_w);
			if (MAP[string(u_str)]==0)	MAP[string(u_str)]=++cnt;
			if (MAP[string(v_str)]==0)	MAP[string(v_str)]=++cnt;
			
			add_edge(MAP[string(u_str)],MAP[string(v_str)],_w);
		}
		
		SPFA(s);
		
		printf( "%d\n",d[t]);
	}
	
	return 0;
}



