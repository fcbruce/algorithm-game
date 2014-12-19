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
#define INF_LL 0x3f3f3f3f3f3f3f3fLL
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 10007<<2
#define maxn 107

using namespace std;

int fir[maxn],p[maxn];
long long flow[maxm],cost[maxm],cap[maxm];
int u[maxm],v[maxm],rev[maxm],nex[maxm];
int q[maxm];
bool inq[maxm];
long long d[maxn];
int e_max;
long long D,K;


void SPFA(int s)
{
    memset(d,0x3f,sizeof d);
    memset(inq,0,sizeof inq);
    d[s]=0;
    int f,r;
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
                    inq[v[e]]=true;
                    q[++r]=v[e];
                }
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;

    while (~scanf("%d %d",&n,&m))
    {
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            int e=e_max++;
            scanf("%d %d %lld",&u[e],&v[e],&cost[e]);
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=v[e-1];v[e]=u[e-1];cost[e]=-cost[e-1];
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e-1;
            e=e_max++;
            u[e]=u[e-1];v[e]=v[e-1];cost[e]=-cost[e-1];
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=v[e-1];v[e]=u[e-1];cost[e]=-cost[e-1];
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e-1;
        }
        scanf("%lld %lld",&D,&K);
        for (int i=0;i<e_max;i++)
        {
            if (i&1)
                cap[i]=0;
            else
                cap[i]=K;
        }



        memset(flow,0,sizeof flow);

        LL total_flow=0,total_cost=0;

        int s=1,t=n;
        for (;;)
        {
            SPFA(s);

            if (d[t]==INF_LL) break;

            long long _f=INF_LL;

            for(int e=p[t];;e=p[u[e]])
            {
                _f=min(_f,cap[e]-flow[e]);
                if (u[e]==s)break;
            }

            for(int e=p[t];;e=p[u[e]])
            {
                flow[e]+=_f;
                flow[rev[e]]-=_f;
                if (u[e]==s)break;
            }

            if (total_flow+_f<D)
            {
                total_flow+=_f;
                total_cost+=d[t]*_f;
            }
            else
            {
                total_cost+=d[t]*(D-total_flow);
                total_flow=D;
                break;
            }
        }

        if (total_flow==D)
            printf("%lld\n",total_cost);
        else
            puts("Impossible.");

    }

    return 0;
}
