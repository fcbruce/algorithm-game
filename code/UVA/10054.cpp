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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

int g[51][51];
bool f=true;
int deg[51];
int n,T,cnt,MAX;

inline void init()
{
    memset(deg,0,sizeof(deg));
    memset(g,0,sizeof(g));

    T=cnt=MAX=0;
    f=true;
}

void euler(int u)
{
    for (int v=1;v<=MAX;v++)
    {
        if (g[u][v])
        {
            g[u][v]--;g[v][u]--;
            euler(v);
            printf("%d %d\n",v,u);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt,u,v;
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        if (t!=1)   puts("");
        printf("Case #%d\n",t);

        init();

        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            //printf("%d %d\n",u,v);
            g[u][v]++;g[v][u]++;
            MAX=max(MAX,max(u,v));
            deg[u]++;deg[v]++;
        }

        for (int i=1;i<=MAX && f;i++)
        {
            //printf("%d\n",deg[i]);
            if (deg[i]&1)
                f=false;
        }

        if (f)
        {
            euler(MAX);
        }
        else
        {
            puts("some beads may be lost");
        }

    }

    return 0;
}
