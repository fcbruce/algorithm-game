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
#define maxm 40007
#define maxn 1007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],cost[maxm],nex[maxm];
int e_max;
int q[maxm<<3],d[maxn],p[maxn];
bool inq[maxn];

void add_edge(int _u,int _v,int _cap,int _cost)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_cap;cost[e]=_cost;
    nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;cost[e]=-_cost;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
    int f,r;
    memset(d,0x3f,sizeof d);
    memset(inq,0,sizeof inq);
    d[s]=0;
    q[f=r=0]=s;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];~e;e=nex[e])
        {
            if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+cost[e])
            {
                d[v[e]]=d[u[e]]+cost[e];
                p[v[e]]=e;
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                }
            }
        }
    }
}

pair<int,int> min_cost_flow(int s,int t)
{
    memset(flow,0,sizeof flow);
    int total_flow=0,total_cost=0;

    for (;;)
    {
        SPFA(s);

        if (d[t]==INF) return make_pair(total_cost,total_flow);

        int _f=INF;

        for (int e=p[t];;e=p[u[e]])
        {
            _f=min(_f,cap[e]-flow[e]);
            if (u[e]==s)    break;
        }


        for (int e=p[t];;e=p[u[e]])
        {
            flow[e]+=_f;
            flow[e^1]-=_f;
            if (u[e]==s)    break;
        }

        total_flow+=_f;
        total_cost+=_f*d[t];
    }

    return make_pair(total_cost,total_flow);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,s,t,_u,_v,_w;
    scanf("%d%d",&n,&m);

    s=0;t=n;
    memset(fir,-1,sizeof fir);
    e_max=0;
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %d",&_u,&_v,&_w);
        add_edge(_u,_v,1,_w);
        add_edge(_v,_u,1,_w);
    }
    add_edge(s,1,2,0);

    printf("%d\n",min_cost_flow(s,t).first);

    return 0;
}
