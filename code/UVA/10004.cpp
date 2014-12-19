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

int g[222][222];
int col[222];
bool f;
int n,m;

void dfs(int x,int c)
{
    if (!f) return ;

    if (col[x]==-1)
    {
        col[x]=c;
        for (int i=0;i<n;i++)
            if (g[x][i])
                dfs(i,c^1);
    }
    else
    {
        if (col[x]!=c)
        {
            f=false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d",&n),n)
    {
        int u,v;
        memset(g,0,sizeof g);
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u][v]=g[v][u]=1;
        }
        memset(col,-1,sizeof(col));

        f=true;
        dfs(0,0);

        for (int i=0;i<n;i++)
            if (col[i]==-1)
                f=false;

        if (f)
            puts("BICOLORABLE.");
        else
            puts("NOT BICOLORABLE.");

    }



    return 0;
}
