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
#define maxm 70007<<1
#define maxn 5007

using namespace std;

const long long INFLL=0x3f3f3f3f3f3f3f3f;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
long long cap[maxm],flow[maxm];
int e_max;
int iter[maxn],q[maxn],lv[maxn];

void add_edge(int _u,int _v,long long _w)
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

long long dinic_dfs(int _u,int t,long long _f)
{
    if (_u==t)  return _f;
    for (int &e=iter[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[_u]<lv[v[e]])
        {
            long long _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
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

long long max_flow(int s,int t)
{

    memset(flow,0,sizeof flow);
    long long total_flow=0;

    for (;;)
    {
        dinic_bfs(s);
        if (lv[t]<0)    return total_flow;
        memcpy(iter,fir,sizeof iter);
        long long _f;

        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;
    }

    return total_flow;
}

int cnt=0;
bool vis[maxn];
void dfs(int _u)
{
    cnt++;
    vis[_u]=true;
    for (int e=fir[_u];~e;e=nex[e])
        if (!vis[v[e]] && cap[e]>flow[e])
            dfs(v[e]);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,w;
    long long W=0;
    scanf("%d%d",&n,&m);
    int s=0,t=n+1;
    e_max=0;
    memset(fir,-1,sizeof fir);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w);
        if (w>0)
        {
            W+=w;
            add_edge(s,i,w);
        }
        if (w<0)
        {
            add_edge(i,t,-w);
        }
    }

    int _u,_v;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&_u,&_v);
        add_edge(_u,_v,INFLL);
    }

    long long max_profit=W-max_flow(s,t);

    memset(vis,0,sizeof vis);
    dfs(s);

    printf("%d %I64d\n",--cnt,max_profit);



    return 0;
}
