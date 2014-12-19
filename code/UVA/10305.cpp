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
#define mm

using namespace std;

bool g[101][101];
int vis[101],topo[101],t;
int n,m;

void dfs(int u)
{
    vis[u]=1;
    for (int v=1;v<=n;v++)
    {
        if (g[u][v])
        {
            if (!vis[v]) dfs(v);
        }
    }

    topo[--t]=u;
}

void toposort()
{
    t=n;
    for (itn u=1;u<=n;u++)
    {
        if (!vis[u])
            dfs(u);
    }
}

void init()
{
    memset(g,false,sizeof g);
    memset(vis,0,sizeof vis);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d",&n,&m),n||m)
    {
        init();
        int u,v;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u][v]=true;
        }


        toposort();

        printf("%d",topo[0]);
        for (int i=1;i<n;i++)
            printf(" %d",topo[i]);
        puts("");
    }

    return 0;
}
