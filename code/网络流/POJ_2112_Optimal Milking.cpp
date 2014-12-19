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
#define maxm 13000
#define maxn 300

using namespace std;

int G[maxn][maxn];

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int d[maxn],p[maxn];
int q[maxm];

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

//    printf("%d\n",total_flow);

    return total_flow;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int l=INF,r=0,K,C,M;

    scanf("%d %d %d",&K,&C,&M);
    for (int i=1;i<=K+C;i++)
        for (int j=1;j<=K+C;j++)
            scanf("%d",&G[i][j]),G[i][j]=G[i][j]?G[i][j]:INF;

    for (int k=1;k<=K+C;k++)
        for (int i=1;i<=K+C;i++)
            for (int j=1;j<=K+C;j++)
                G[i][j]=min(G[i][k]+G[k][j],G[i][j]);
    int ans=-1;
//    printf("%d %d\n",l,r);
    l=0;r=INF;
    while (l<=r)
    {
        int mid=l+r>>1;
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=K+1;i<=K+C;i++)
            add_edge(0,i,1);

        for (int i=1;i<=K;i++)
            add_edge(i,K+C+1,M);

        for (int i=K+1;i<=K+C;i++)
            for (int j=1;j<=K;j++)
                if (G[i][j]<=mid)
                    add_edge(i,j,1);

//        printf("mid=%d\n",mid);

        if (max_flow(0,K+C+1)==C)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d\n",ans);


    return 0;
}
