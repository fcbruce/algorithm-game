#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 23456
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int p[maxn],q[maxn],d[maxn];

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

int max_flow(int s,int t)
{
    memset(flow,0,sizeof flow);
    int total_flow=0;

    for (;;)
    {
        memset(d,0,sizeof d);
        d[s]=INF;
        int f=0,r=0;
        q[0]=s;
        while (f<=r)
        {
            int _u=q[f++];
            for (int e=fir[_u];~e;e=nex[e])
            {
                if (!d[v[e]] && cap[e]>flow[e])
                {
                    q[++r]=v[e];
                    p[v[e]]=e;
                    d[v[e]]=min(d[u[e]],cap[e]-flow[e]);
                }
            }
        }

        if (d[t]==0) break;

        for (int e=p[t];;e=p[u[e]])
        {
            flow[e]+=d[t];
            flow[e^1]-=d[t];
            if (u[e]==s) break;
        }

        total_flow+=d[t];
    }

    return total_flow;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,np,nc,m,_u,_v,_w;

    while (~scanf("%d %d %d %d",&n,&np,&nc,&m))
    {
        e_max=0;
        int s=n,t=n+1;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            scanf(" (%d,%d)%d",&_u,&_v,&_w);
            add_edge(_u,_v,_w);
        }
        for (int i=0;i<np;i++)
        {
            scanf(" (%d)%d",&_u,&_w);
            add_edge(s,_u,_w);
        }

        for (int i=0;i<nc;i++)
        {
            scanf(" (%d)%d",&_u,&_w);
            add_edge(_u,t,_w);
        }

        printf("%d\n",max_flow(s,t));
    }


    return 0;
}
