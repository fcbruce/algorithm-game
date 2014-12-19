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
#define maxm 1000007<<1
#define maxn 200007
#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

int pre[maxn],low[maxn],fir[maxn],e_bcc[maxn];
int u[maxm],v[maxm],nex[maxm];
bool isbridge[maxm],vise[maxm];
int n,m,e_max,dfs_clock,bcc_cnt,b_cnt;

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    for (int e=fir[_u];~e;e=nex[e])
    {
        int _v=v[e];
        if (!pre[_v])
        {
            vise[e]=vise[e^1]=true;
            tarjan_dfs(_v);
            low[_u]=min(low[_u],low[_v]);
            if (pre[_u]<low[_v])    {isbridge[e]=isbridge[e^1]=true;b_cnt++;}
        }
        else
        {
            if (pre[_v]<pre[_u] && !vise[e])
            {
                vise[e]=vise[e^1]=true;
                low[_u]=min(low[_u],pre[_v]);
            }
        }
    }
}

void find_bridge()
{
    dfs_clock=b_cnt=0;
    memset(isbridge,0,sizeof isbridge);
    memset(pre,0,sizeof pre);
    memset(vise,0,sizeof vise);

    for (int i=1;i<=n;i++)
    {
        if (!pre[i])    tarjan_dfs(i);
    }
}

void dfs(int _u)
{
    e_bcc[_u]=bcc_cnt;
    for (int e=fir[_u];~e;e=nex[e])
    {
        int _v=v[e];
        if (!e_bcc[_v] && !isbridge[e])
        {
            dfs(_v);
        }
    }
}

void edge_bcc()
{
    find_bridge();//找桥
    memset(e_bcc,0,sizeof e_bcc);
    bcc_cnt=0;
    //DFS分出边双联通
    for (int i=1;i<=n;i++)
    {
        if (!e_bcc[i])
        {
            bcc_cnt++;
            dfs(i);
        }
    }

}

int d[maxn],q[maxm];
bool inq[maxn];
int f,r;

void SPFA(int _u)
{
    memset(d,0x3f,sizeof d);
    memset(inq,0,sizeof inq);
    d[_u]=0;
    f=0;r=-1;
    q[++r]=_u;
    int MAX=0;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];~e;e=nex[e])
        {
            if (d[v[e]]>d[u[e]]+1)
            {
                d[v[e]]=d[u[e]]+1;
                MAX=max(MAX,d[v[e]]);
                if (!inq[v[e]])
                {
                    inq[v[e]]=true;
                    q[++r]=v[e];
                }
            }
        }
    }

}

int dp[maxn];
bool visv[maxn];

int dp_dfs(int _u)
{
    if (dp[_u]!=-1) return dp[_u];

    for (int e=fir[_u];~e;e=nex[e])
    {
        if (!visv[v[e]])
        {
            visv[v[e]]=true;
            dp[_u]=max(dp[_u],dp_dfs(v[e]));
            visv[v[e]]=false;
        }

    }

    printf("dp[%d] %d\n",_u,++dp[_u]);

    return dp[_u];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int x,y;

    while (scanf("%d %d",&n,&m),n||m)
    {

        memset(fir,-1,sizeof fir);
        e_max=-1;
        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            e_max++;
            u[e_max]=x;v[e_max]=y;
            nex[e_max]=fir[x];
            fir[x]=e_max;
            e_max++;
            u[e_max]=y;v[e_max]=x;
            nex[e_max]=fir[y];
            fir[y]=e_max;
        }

        edge_bcc();

        int bccemax=-1;
        memset(fir,-1,sizeof fir);
        for (itn e=0;e<=e_max;e++)
        {
            if (e_bcc[u[e]]==e_bcc[v[e]])   continue;
            bccemax++;
            u[bccemax]=e_bcc[u[e]];v[bccemax]=e_bcc[v[e]];
            nex[bccemax]=fir[u[bccemax]];
            fir[u[bccemax]]=bccemax;
        }

        SPFA(1);
        int MAXV=-1;
        for (int i=1;i<=bcc_cnt;i++)
            if (MAXV==-1 || d[MAXV]<d[i])   MAXV=i;

        SPFA(MAXV);
        MAXV=-1;
        for (int i=1;i<=bcc_cnt;i++)
            if (MAXV==-1 || d[MAXV]<d[i])   MAXV=i;

        printf("%d\n",b_cnt-d[MAXV]);

    }


    return 0;
}
