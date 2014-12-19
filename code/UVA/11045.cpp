/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-04 20:47:21 
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
#define maxn 64

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int iter[maxn],q[maxn],lv[maxn];

void add_edge(int _u,int _v,int _w)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(int s)
{
    int f,r;
    memset(lv,-1,sizeof lv);
    q[f=r=0]=s;
    lv[s]=0;
    while(f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if (cap[e]>flow[e] && lv[v[e]]<0)
            {
                lv[v[e]]=lv[u[e]]+1;
                q[++r]=v[e];
            }
        }
    }
}

int dinic_dfs(int _u,int t,int _f)
{
    if (_u==t)  return _f;
    for (int &e=iter[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[_u]<lv[v[e]])
        {
            int _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
            if (_d>0)
            {
                flow[e]+=_d;
                flow[e^1]-=_d;
                return _d;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t)
{

    memset(flow,0,sizeof flow);
    int total_flow=0;

    for (;;)
    {
        dinic_bfs(s);
        if (lv[t]<0)    return total_flow;
        memcpy(iter,fir,sizeof iter);
        int _f;

        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;
    }

    return total_flow;
}

char _size[7][5]={ "","XS","S","M","L","XL","XXL"};

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int T_T;
	int n,m;
	
	scanf( "%d",&T_T);
	while (T_T--)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		
		scanf( "%d%d",&n,&m);
		
		int s=0,t=m+7;
		
		char s1[5],s2[5];
		
		for (int i=0;i<m;i++)
		{
			add_edge(s,i+7,1);
			scanf( "%s%s",s1,s2);
			for (int j=1;j<7;j++)
				if (strcmp(s1,_size[j])==0)	add_edge(i+7,j,1);
			for (int j=1;j<7;j++)
				if (strcmp(s2,_size[j])==0)	add_edge(i+7,j,1);
		}
		
		for (int i=1;i<7;i++)
			add_edge(i,t,n/6);
		
		if (max_flow(s,t)==m)
			puts( "YES");
		else
			puts( "NO");
	}
	
	return 0;
}



