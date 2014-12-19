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
#define maxm 11111
#define maxn 207

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int lv[maxn],iter[maxn],q[maxn];

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
    lv[s]=0;
    q[f=r=0]=s;
    while (f<=r)
    {
        int x=q[f++];
        for (itn e=fir[x];~e;e=nex[e])
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
        if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
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

        if (lv[t]<0)    return  total_flow;

        memcpy(iter,fir,sizeof iter);

        int _f;
        while ((_f=dinic_dfs(s,t,INF))>0){
            total_flow+=_f;
        }


    }

    return total_flow;
}

bool vis[maxn];

void dfs(int _u)
{
    vis[_u]=true;
    for (int e=fir[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && !vis[v[e]])
            dfs(v[e]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,_u,_v,_w;

    scanf("%d %d",&n,&m);
    int s=0,t=n+n+1;
    memset(fir,-1,sizeof fir);
    e_max=0;

    for (int i=n+1;i<=n+n;i++)
    {
        scanf("%d",&_w);
        add_edge(i,t,_w);
    }

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&_w);
        add_edge(s,i,_w);
    }

    for (int i=0;i<m;i++)
    {
        scanf("%d %d",&_u,&_v);
        add_edge(_u,_v+n,INF);
    }

    printf("%d\n",max_flow(s,t));

    memset(vis,0,sizeof vis);

    dfs(s);

    int cnt=0;

    for (int i=1;i<=n;i++)
        if (!vis[i]) cnt++;

    for (int i=n+1;i<=n+n;i++)
        if (vis[i]) cnt++;

    printf("%d\n",cnt);

    for (int i=1;i<=n;i++)
        if (!vis[i]) printf("%d -\n",i);

    for (int i=n+1;i<=n+n;i++)
        if (vis[i]) printf("%d +\n",i-n);



    return 0;
}
