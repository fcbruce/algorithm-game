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
#define maxm 20007
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm],rev[maxm];
int e_max;
int d[maxn],p[maxn];
int q[maxm];
int last_pig[1001],pig[1001];

void add_edge(int _u,int _v,int _w)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e+1;

    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;
    nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e-1;
}

int max_flow(int s,int t)
{
    memset(flow,0,sizeof flow);
    int total_flow=0;
    for (;;)
    {
        memset(d,0,sizeof d);
        d[s]=INF;
        int r=0,f=0;
        q[0]=s;
        while (f<=r)
        {
            int _u=q[f++];
            for (int e=fir[_u];~e;e=nex[e])
            {
                if (!d[v[e]] && cap[e]>flow[e])
                {
                    p[v[e]]=e;
                    q[++r]=v[e];
                    d[v[e]]=min(d[u[e]],cap[e]-flow[e]);
                }
            }
        }

        if (d[t]==0)    break;

        for (int e=p[t];;e=p[u[e]])
        {
            flow[e]+=d[t];
            flow[rev[e]]-=d[t];
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

    int n,m;
    while (~scanf("%d %d",&m,&n))
    {
        memset(last_pig,0,sizeof last_pig);
        memset(fir,-1,sizeof fir);
        e_max=0;
        for (int i=1;i<=m;i++)  scanf("%d",pig+i);
        for (int i=1;i<=n;i++)
        {
            itn keys,id,need;
            scanf("%d",&keys);
            int rec=0;
            for (int j=0;j<keys;j++)
            {
                scanf("%d",&id);
                if (last_pig[id]==0)
                {
                    rec+=pig[id];
                }
                else
                {
                    add_edge(last_pig[id],i,INF);
                }
                last_pig[id]=i;
            }

            if (rec)    add_edge(0,i,rec);

            scanf("%d",&need);
            add_edge(i,n+1,need);
        }

        printf("%d\n",max_flow(0,n+1));
    }

    return 0;
}
