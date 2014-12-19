/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-25 10:33:17 
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
#define maxn 1007

using namespace std;

int fir1[maxn],fir2[maxn];
int u1[maxm],v1[maxm],w1[maxm],nex1[maxm];
int u2[maxm],v2[maxm],w2[maxm],nex2[maxm];
int e_max1,e_max2;
int p1[maxn][maxn],p2[maxn][maxn];
int g1[maxn][maxn],g2[maxn][maxn];
int q[maxm<<3];
bool inq[maxn];
int st[maxn];

void SPFA1(int s)
{
	int f,r;
	memset(g1[s],0,sizeof g1[s]);
	memset(inq,0,sizeof inq);
	g1[s][s]=0;
	p1[s][s]=-1;
	q[f=r=0]=s;
	
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir1[x];~e;e=nex1[e])
		{
			if (g1[s][v1[e]]<g1[s][u1[e]]+w1[e])
			{
				g1[s][v1[e]]=g1[s][u1[e]]+w1[e];
				p1[s][v1[e]]=u1[e];
				if (!inq[v1[e]])
				{
					inq[v1[e]]=true;
					q[++r]=v1[e];
				}
			}
		}
	}
}

void SPFA2(int s)
{
	int f,r;
	memset(g2[s],0x3f,sizeof g2[s]);
	memset(inq,0,sizeof inq);
	g2[s][s]=0;
	p2[s][s]=-1;
	q[f=r=0]=s;
	
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir2[x];~e;e=nex2[e])
		{
			if (g2[s][v2[e]]>g2[s][u2[e]]+w2[e])
			{
				g2[s][v2[e]]=g2[s][u2[e]]+w2[e];
				p2[s][v2[e]]=u2[e];
				if (!inq[v2[e]])
				{
					inq[v2[e]]=true;
					q[++r]=v2[e];
				}
			}
		}
	}
}

void add_edge(int _u,int _v,int _w,int type)
{
	if (type==1)
	{
		int e=e_max1++;
		u1[e]=_u;v1[e]=_v;w1[e]=_w;
		nex1[e]=fir1[u1[e]];fir1[u1[e]]=e;
	}
	else
	{
		int e=e_max2++;
		u2[e]=_u;v2[e]=_v;w2[e]=_w;
		nex2[e]=fir2[u2[e]];fir2[u2[e]]=e;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m,k,T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d%d%d",&n,&m,&k);
		
		memset(fir1,-1,sizeof fir1);
		memset(fir2,-1,sizeof fir2);
		e_max1=e_max2=0;
		
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,w,1);
		}
		
		for (int i=0,u,v,w;i<k;i++)
		{
			scanf( "%d%d%d",&u,&v,&w);
			add_edge(u,v,w,2);
		}
		
		for (int i=1;i<=n;i++)
		{
			SPFA1(i);
			SPFA2(i);
		}
		
		double fear=0;
		int s,t;
		
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i!=j && g1[i][j]!=0 && g2[j][i]!=INF)
				{
					if (fear<(double)g1[i][j]/(double)g2[j][i])
					{
						fear=(double)g1[i][j]/(double)g2[j][i];
						s=i;
						t=j;
					}
				}
			}
		}
		
		int top=-1;
		for (int x=s;~x;x=p2[t][x])
			st[++top]=x;
		while (top>=0)	printf( "%d ",st[top--]);
		
		top=-1;
		for (int x=t;~x;x=p1[s][x])
			st[++top]=x;
		top--;
		while (top>=0)	printf( "%d%c",st[top--],top?' ':'\n');
		
		printf( "%.3f\n",fear);
		
	
		
	}
	
	return 0;
}



