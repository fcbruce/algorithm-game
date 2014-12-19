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
#define maxm 555555
#define maxn 55

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
long long w[maxn];
int n;

int pre[maxn],low[maxn],sccno[maxn];
int st[maxn],top;
int dfs_clock,scc_cnt;

int deg[maxn];

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
        while (true)
        {
            int x=st[top--];
            sccno[x]=scc_cnt;
            if (x==_u)   break;
        }
    }
}

void find_scc()
{
    dfs_clock=scc_cnt=0;
    top=-1;
    memset(sccno,0,sizeof sccno);
    memset(pre,0,sizeof pre);
    for (int i=0;i<n;i++)
    {
        if (pre[i]==0)  tarjan_dfs(i);
    }
}

long long dfs(int _u)
{
    long long temp=1;
    for (int e=fir[_u];~e;e=nex[e])
    {
        temp*=dfs(v[e]);
    }

    return temp+1;
}

class InvariantSets
{
public:
    long long countSets(vector <int> f)
    {
        n=f.size();

        memset(fir,-1,sizeof fir);

        for (int i=0;i<n;i++)
        {
            u[i]=i;v[i]=f[i];
            nex[i]=fir[i];fir[i]=i;
        }

        find_scc();

        memset(fir,-1,sizeof fir);
        memset(deg,0,sizeof deg);

        int e=0;

        for (int i=0;i<n;i++)
        {
            if (sccno[u[i]]==sccno[v[i]])   continue;

            u[e]=sccno[u[i]];v[e]=sccno[v[i]];

            swap(u[e],v[e]);

            nex[e]=fir[u[e]];
            deg[v[e]]++;
            fir[u[e]]=e++;
        }

        for (int i=1;i<=scc_cnt;i++)
        {
            if (deg[i]==0)
            {
                u[e]=i;v[e]=0;
                swap(u[e],v[e]);
                nex[e]=fir[u[e]];
                fir[u[e]]=e++;
            }
        }

        return dfs(0)-1;



    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    InvariantSets a;
    itn x,y;
    while (~scanf("%d",&x))
    {
        vector <int>    v;
        for (int i=0;i<x;i++)
        {
            scanf("%d",&y);
            v.push_back(y);
        }

        printf("%lld\n",a.countSets(v));
    }


    return 0;
}
