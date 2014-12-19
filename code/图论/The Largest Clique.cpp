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
#define mm 50007
#define nn 1007

using namespace std;

int fir[nn],w[nn],sccno[nn],pre[nn],low[nn];
int u[mm],v[mm],nex[mm];
int st[nn],top;
int dfs_clock,scc_cnt;
int n,m;

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    st[++top]=_u;
    for (int e=fir[_u];e!=-1;e=nex[e])
    {
        if (!pre[v[e]])
        {
            tarjan_dfs(v[e]);
            low[_u]=min(low[_u],low[v[e]]);
        }
        else
        {
            if (!sccno[v[e]])
            {
                low[_u]=min(low[_u],pre[v[e]]);
            }
        }
    }

    if (pre[_u]==low[_u])
    {
        scc_cnt++;
        while (true)
        {
            int x=st[top--];
            sccno[x]=scc_cnt;
            w[scc_cnt]++;
            if (x==_u)  break;
        }
    }

}

void find_scc()
{
    dfs_clock=scc_cnt=0;
    top=-1;
    memset(sccno,0,sizeof sccno);
    memset(pre,0,sizeof pre);
    for (int i=1;i<=n;i++)
    {
        if (!pre[i])   tarjan_dfs(i);
    }
}

int dp[nn];

int dfs(int _u)
{
    if (dp[_u]!=0)  return dp[_u];

    for (int e=fir[_u];e!=-1;e=nex[e])
    {
        dp[_u]=max(dp[_u],dfs(v[e]));
    }

    dp[_u]+=w[_u];
    return dp[_u];
}

int d[nn];
bool inq[nn];
itn q[mm];
int f,r;
int MAX;

int SPFA(int _u)
{
    memset(d,0,sizeof d);
    memset(inq,0,sizeof inq);
    MAX=0;
    q[f=r=0]=_u;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (itn e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]<d[u[e]]+w[v[e]])
            {
                d[v[e]]=d[u[e]]+w[v[e]];
                MAX=max(d[v[e]],MAX);
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                }
            }
        }
    }

    return MAX;

}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d %d",&n,&m);
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&u[i],&v[i]);
            nex[i]=fir[u[i]];
            fir[u[i]]=i;
        }

        memset(w,0,sizeof w);

        find_scc();

        int e_max=-1;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            if (sccno[u[i]]==sccno[v[i]])   continue;

            ++e_max;
            u[e_max]=sccno[u[i]];v[e_max]=sccno[v[i]];
            nex[e_max]=fir[u[e_max]];
            fir[u[e_max]]=e_max;
        }
        for (itn i=1;i<=scc_cnt;i++)
        {
            ++e_max;
            u[e_max]=0;v[e_max]=i;
            nex[e_max]=fir[0];
            fir[0]=e_max;
        }



        memset(dp,0,sizeof dp);

//        printf("%d\n",SPFA(0));

        printf("%d\n",dfs(0));


    }


    return 0;
}
