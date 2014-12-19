/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-18 10:06:04 
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
#define maxm 23333
#define maxn 233

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn],__prev[maxn],__pren[maxn];
int q[maxm<<3];
bool inq[maxn];
int n;

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
	int f,r;
	memset(inq,0,sizeof inq);
	memset(d,0x3f,sizeof d);
	d[s]=0;
	q[f=r=0]=s;
	__pren[s]=0;
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e] || 
				(d[v[e]]==d[u[e]]+w[e] && __prev[v[e]]>u[e]))
			{
				d[v[e]]=d[u[e]]+w[e];
				__prev[v[e]]=u[e];
				__pren[v[e]]=__pren[u[e]]+1;
				if (!inq[v[e]])
				{
					inq[v[e]]=true;
					q[++r]=v[e];
				}
			}
		}
	}
}


int st[maxn];
void write(int s,int t)
{
	int top=-1;
	
	printf( "Path: %d",s);
	for (int v=__prev[s];v!=t+n;v=__prev[v])
		if (v>n)	continue;
		else		printf( "-->%d",v);
	printf( "-->%d",t);
		
//	printf( "Path: %d",s);
//	for (int i)
//	while (top>=0)
//		if (st[top]>n)
//			top--;
//		else
//			printf( "-->%d",st[top--]);
	
	putchar( '\n');
		
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE

	
	while (scanf( "%d",&n),n)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		for (int i=1,_w;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				scanf( "%d",&_w);
				if (_w>=0 && i!=j)
					add_edge(j+n,i,_w);
			}
		}
		
		for (int i=1,_w;i<=n;i++)
		{
			scanf( "%d",&_w);
			add_edge(i,i+n,_w);
		}
		
		int s,t;
		while (scanf( "%d %d",&s,&t),~s && ~t)
		{
			SPFA(t+n);
			printf( "From %d to %d :\n",s,t);
			
			if (s==t)
			{
//				for (;;);
				printf( "Path: %d\n",s);
				printf( "Total cost : 0\n");
				putchar( '\n');
				continue;
			}
			
			write(s,t);
			printf( "Total cost : %d\n",d[s]);
			putchar( '\n');
		}
	}
	
	return 0;
}



