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
#define maxm 100007
#define maxn 100007

using namespace std;

struct path
{
    int u,v,depth,lca;
    bool operator < (const path &p)const
    {
        return depth>p.depth;
    }
}p[maxm];

int fir[maxn];
int u[maxm<<1],v[maxm<<1],nex[maxm<<1];
int e_max;
int root;

int q[maxn];
int depth[maxn],par[20][maxn];
bool del[maxn];

int n,m;

void add_edge(int _u,int _v)
{
    int e=e_max++;
    u[e]=_u;v[e]=_v;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void build_tree(int s,int p,int d)
{
    int f,r;
    par[0][s]=p;
    depth[s]=d;
    q[f=r=0]=s;

    while (f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if (v[e]!=par[0][x])
            {
                par[0][v[e]]=u[e];
                depth[v[e]]=depth[u[e]]+1;
                q[++r]=v[e];
            }
        }
    }
}

void init_lca()
{
    build_tree(root,-1,1);

    for (int k=0;k+1<18;k++)
    {
        for (int _u=1;_u<=n;_u++)
        {
            if (par[k][_u]<0)   par[k+1][_u]=-1;
            else    par[k+1][_u]=par[k][par[k][_u]];
        }
    }
}

int lca(int _u,int _v)
{
    if (depth[_u]>depth[_v])    swap(_u,_v);

    for (int k=0;k<18;k++)
        if ((depth[_v]-depth[_u])>>k&1)
            _v=par[k][_v];

    if (_u==_v) return _u;

    for (int k=17;k>=0;k--)
    {
        if (par[k][_u]!=par[k][_v])
        {
            _u=par[k][_u];
            _v=par[k][_v];
        }
    }

    return par[0][_u];
}

void __del(int s)
{
    int f,r;
    del[s]=true;
    q[f=r=0]=s;
    while (f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if (!del[v[e]] && depth[v[e]]>depth[u[e]])
            {
                del[v[e]]=true;
                q[++r]=v[e];
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    unsigned long long seed=1331^(~0ull);

    while (~scanf("%d %d",&n,&m))
    {
        int _u,_v;
        seed=(seed*1331)^seed;
        seed^=(~0ull);
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=1;i<n;i++)
        {
            seed=(seed*1331)^seed;
            seed^=(~0ull);
            scanf("%d %d",&_u,&_v);
//            _u=ReadInt();
//            _v=ReadInt();
            add_edge(_u,_v);
            add_edge(_v,_u);
        }

        root=(seed*1331)%n+1;
        seed=(seed*1331)^seed;
        seed^=(~0ull);

        init_lca();

        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&p[i].u,&p[i].v);
//            p[i].u=ReadInt();
//            p[i].v=ReadInt();
            p[i].lca=lca(p[i].u,p[i].v);
            p[i].depth=depth[p[i].lca];
        }

        sort(p,p+m);

        memset(del,0,sizeof del);

        int cnt=0;

        for (int i=0;i<m;i++)
        {
            if (!del[p[i].u] && !del[p[i].v])
            {
                cnt++;
                __del(p[i].lca);
            }
        }

        printf("%d\n",cnt);

    }

    return 0;
}
