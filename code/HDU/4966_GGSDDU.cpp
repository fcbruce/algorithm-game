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
#define maxm (55*505)+2333
#define maxn (55*505)

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max,v_max;
int __hash[55][505];
int a[55];
int __prev[maxn],cir_no[maxn],vis[maxn],in[maxn];

inline void add_edge(int _u,int _v,int _w)
{
	int e;
	e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

int dmst(int s)
{
	int res=0;
	for (;;)
	{
		memset(in,0x3f,sizeof in);
		for (int e=0;e<e_max;e++)
		{
			if (w[e]<in[v[e]] && u[e]!=v[e])
			{
				in[v[e]]=w[e];
				__prev[v[e]]=u[e];
			}
		}
		
		for (int i=0;i<v_max;i++)
			if (i!=s && in[i]==INF)	return -1;
			
		int cir_cnt=0;
		memset(cir_no,-1,sizeof cir_no);
		memset(vis,-1,sizeof vis);
		in[s]=0;
		
		for (int i=0;i<v_max;i++)
		{
			res+=in[i];
			int _v=i;
			while (vis[_v]!=i && cir_no[_v]==-1 && _v!=s)
			{
				vis[_v]=i;
				_v=__prev[_v];
			}
			
			if (_v!=s && cir_no[_v]==-1)
			{
				for (int _u=__prev[_v];_u!=_v;_u=__prev[_u])
				{
					cir_no[_u]=cir_cnt;
				}
				cir_no[_v]=cir_cnt++;
			}
		}
		
		if (!cir_cnt)	break;
		
		for (int i=0;i<v_max;i++)	
			if (cir_no[i]==-1)
				cir_no[i]=cir_cnt++;
				
		for (int e=0;e<e_max;e++)
		{
			int _v=v[e];
			u[e]=cir_no[u[e]];
			v[e]=cir_no[v[e]];
			if (u[e]!=v[e])
				w[e]-=in[_v];
		}
		
		v_max=cir_cnt;
		s=cir_no[s];
	}
	
	return res;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m;
	while (scanf( "%d%d",&n,&m),n||m)
	{
		for (int i=0;i<n;i++)
			scanf( "%d",a+i);
			
		e_max=0;v_max=1;
		memset(fir,-1,sizeof fir);
		memset(__hash,-1,sizeof __hash);
		
		for (int i=0;i<n;i++)
		{
			__hash[i][0]=0;
			for (int j=1;j<=a[i];j++)
			{
				__hash[i][j]=v_max++;
				add_edge(__hash[i][j],__hash[i][j-1],0);
			}
		}
		
		for (int i=0,c,d,l1,l2,w;i<m;i++)
		{
			scanf( "%d%d%d%d%d",&c,&l1,&d,&l2,&w);
			add_edge(__hash[c-1][l1],__hash[d-1][l2],w);
		}
		
		printf( "%d\n",dmst(0));
	}
	
	return 0;
}



