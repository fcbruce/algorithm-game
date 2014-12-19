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
#define maxm 50000
#define maxn 20007

using namespace std;

int in[maxn],out[maxn];
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int sccno[maxn],pre[maxn],low[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;
int n,m;

void tarjan_dfs(int _u)
{
    pre[_u]=low[_u]=++dfs_clock;
    st[++top]=_u;
    for (int e=fir[_u];~e;e=nex[e])
    {
        int _v=v[e];
        if (!pre[_v])
        {
            tarjan_dfs(_v);
            low[_u]=min(low[_u],low[_v]);
        }
        else
        {
            if (!sccno[_v])
            {
                low[_u]=min(low[_u],pre[_v]);
            }
        }
    }

    if (pre[_u]==low[_u])
    {
        ++scc_cnt;
        while (true)
        {
            int x=st[top--];
            sccno[x]=scc_cnt;
            if (x==_u) break;
        }
    }
}

void find_scc()
{
    scc_cnt=dfs_clock=0;top=-1;
    memset(pre,0,sizeof pre);
    memset(sccno,0,sizeof sccno);
    for (int i=1;i<=n;i++)
    {
        if (!pre[i])    tarjan_dfs(i);
    }
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
        for (itn i=0;i<m;i++)
        {
            scanf("%d %d",&u[i],&v[i]);
            nex[i]=fir[u[i]];
            fir[u[i]]=i;
        }

        find_scc();

        if (scc_cnt==1)
        {
            printf("%d\n",0);
            continue;
        }

        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        for (int i=0;i<m;i++)
        {
            if (sccno[u[i]]==sccno[v[i]])   continue;

            in[sccno[v[i]]]++;
            out[sccno[u[i]]]++;
        }

        int a=0,b=0;
        for (itn i=1;i<=scc_cnt;i++)
        {
            if (in[i]==0)   a++;
            if (out[i]==0)  b++;
        }

        printf("%d\n",max(a,b));
    }


    return 0;
}
