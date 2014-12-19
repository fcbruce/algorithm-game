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
#define maxm 4004
#define maxn 404

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

struct EDGE
{
    int u,v,w;
}edge[1111];
int in[222],out[222];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    unsigned long long seed=~0ULL;
    scanf("%d",&T_T);

    while (T_T--)
    {
        int n,m,s,t,full_flow=0;
        e_max=0;
        memset(fir,-1,sizeof fir);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        scanf("%d%d",&n,&m);
        seed=seed^T_T^n^m^(~0ULL);

        srand(seed);

        s=0;t=n+1;

        for (int i=0;i<m;i++)
        {
            scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
            if (edge[i].w==1)
            {
                out[edge[i].u]++;
                in[edge[i].v]++;
                edge[i].w=0;
                continue;
            }
            if (rand()&1)
            {
                edge[i].w=1;
                out[edge[i].u]++;
                in[edge[i].v]++;
                add_edge(edge[i].u,edge[i].v,1);
            }
            else
            {
                edge[i].w=-1;
                out[edge[i].v]++;
                in[edge[i].u]++;
                add_edge(edge[i].v,edge[i].u,1);
            }
        }


        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            if (abs(in[i]-out[i])&1)
            {
                flag=false;
                break;
            }
            else
            {
                if (in[i]==out[i])  continue;
                if (in[i]>out[i])
                    add_edge(i,t,in[i]-out[i]>>1);
                else
                    add_edge(s,i,out[i]-in[i]>>1),full_flow+=out[i]-in[i]>>1;
            }
        }

        if (!flag)
        {
            puts("impossible");
            continue;
        }
        else
        {
            if (max_flow(s,t)==full_flow)
                puts("possible");
            else
                puts("impossible");
        }

    }

    return 0;
}
