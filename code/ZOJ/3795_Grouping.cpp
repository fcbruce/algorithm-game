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
#define mm 300007
#define nn 100007

using namespace std;

itn fir[nn];
itn u[mm],v[mm],nex[mm];
int w[nn];
itn n,m;
int st[mm];
int top;
int far[nn];
int cnt;
int pre[nn],low[nn],sccno[nn],dfs_clock,scc_cnt;

void read_graph()
{
    //scanf("%d %d",&n,&m);
    memset(fir,-1,sizeof fir);

    for (itn e=0;e<m;e++)
    {
        scanf("%d %d",&u[e],&v[e]);
        nex[e]=fir[u[e]];
        fir[u[e]]=e;
    }
}

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    st[++top]=_u;
    for (int e=fir[_u];e!=-1;e=nex[e])
    {
        int _v=v[e];
        if (pre[_v]==0)
        {
            tarjan_dfs(_v);
            low[_u]=min(low[_u],low[_v]);
        }
        else
        {
            if (sccno[_v]==0)
                low[_u]=min(low[_u],pre[_v]);
        }
    }

    if (low[_u]==pre[_u])
    {
        scc_cnt++;
//        printf("scccnt %d\n",scc_cnt);
        while (true)
        {
            int x=st[top--];
//            printf("%d -> %d\n",x,scc_cnt);
            sccno[x]=scc_cnt;
            w[scc_cnt]++;
            if (x==_u)   break;
        }
//        printf("\n");
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
        if (pre[i]==0)  tarjan_dfs(i);
    }
}

itn dp[nn];

int dfs(int _u)
{
//    printf("_u=%d\n",_u);
    if (dp[_u]!=0) return dp[_u];

    for (int e=fir[_u];e!=-1;e=nex[e])
    {
        dp[_u]=max(dp[_u],dfs(v[e]));
    }

    dp[_u]+=w[_u];
    return dp[_u];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE
	int T;
	//scanf("%d",&T);
	while (~scanf("%d %d",&n,&m))
    {
        read_graph();
        memset(w,0,sizeof w);

        find_scc();

        cnt=-1;
        memset(fir,-1,sizeof fir);
        memset(far,0,sizeof far);
//
//        for (int i=1;i<=n;i++)
//        {
//            printf("%d -> %d\n",i,sccno[i]);
//        }
//
//        puts("");

        for (int e=0;e<m;e++)
        {
            if (sccno[u[e]]==sccno[v[e]])   continue;
            ++cnt;

//            printf("(%d->%d)----->(%d->%d)\n",u[e],sccno[u[e]],v[e],sccno[v[e]]);

            u[cnt]=sccno[u[e]];
            v[cnt]=sccno[v[e]];
            nex[cnt]=fir[u[cnt]];
            fir[u[cnt]]=cnt;

            far[v[cnt]]=1;

//            printf("%d %d\n",u[cnt],v[cnt]);

        }

        int ans=0;
        memset(dp,0,sizeof dp);

        for (int i=1;i<=scc_cnt;i++)
        {
            if (far[i]==0)
            {
                //dp[i]=w[i];
                ans=max(ans,dfs(i));
            }
        }

        printf("%d\n",ans);

    }
	return 0;
}
