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
#define maxm 2007
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
double cap[maxm],flow[maxm];
int e_max;
int iter[maxn],lv[maxn],q[maxn];

void add_edge(int _u,int _v,double _w)
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
    memset(lv,-1,sizeof lv);
    lv[s]=0;
    int f,r;
    q[f=r=0]=s;
    while (f<=r)
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

double dinic_dfs(int _u,int t,double _f)
{
    if (_u==t)  return _f;
    for (int &e=iter[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[_u]<lv[v[e]])
        {
            double _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
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

double max_flow(int s,int t)
{
    memset(flow,0,sizeof flow);
    double total_flow=0;

    for (;;)
    {
        dinic_bfs(s);

        if (lv[t]<0)    return total_flow;

        memcpy(iter,fir,sizeof fir);

        double _f;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;

    }

    return total_flow;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m,k,_u,_v;
    double _w;
    scanf("%d",&T_T);

    while (T_T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        int s=0,t=n+m+1;
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=1;i<=n;i++)
        {
            scanf("%lf",&_w);
            add_edge(s,i,log(_w));
        }
        for (int i=n+1;i<=n+m;i++)
        {
            scanf("%lf",&_w);
            add_edge(i,t,log(_w));
        }
        for (int i=0;i<k;i++)
        {
            scanf("%d%d",&_u,&_v);
            add_edge(_u,_v+n,(double)INF);
        }

        printf("%.4f\n",exp(max_flow(s,t)));
    }


    return 0;
}
