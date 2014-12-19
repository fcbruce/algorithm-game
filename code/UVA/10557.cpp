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

int g[101][101];
int G[101][101];
int d[101];
int inq[101];
int cc[101];
int w[101];
int n;

void floyd()
{
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (g[i][k] && g[k][j]) g[i][j]=1;
            }
        }
    }

}

bool loop()
{
    memset(d,0xcf,sizeof(d));
    memset(inq,0,sizeof(inq));
    memset(cc,0,sizeof(cc));
    queue<int> q;
    q.push(1);
    d[1]=100;
    cc[1]=1;

    while (!q.empty())
    {
        int x=q.front();q.pop();
        inq[x]=0;
        if (cc[x]>n)   break;
        for (int e=1;e<=n;e++)
        {
            if (g[x][e] && d[x]>0 && d[x]+w[e]>0 && d[e]<d[x]+w[e])
            {
                d[e]=d[x]+w[e];
                if (!inq[e])
                {
                    inq[e]=1;
                    q.push(e);
                    if (++cc[e]>n)  break;
                }
            }
        }
    }

    if (d[n]>0) return true;


    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (g[i][k] && g[k][j]) g[i][j]=1;
            }
        }
    }

    for (int i=1;i<n;i++)
    {
        if (cc[i]>n && g[1][i] && g[i][n])
            return true;
    }


    return false;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d",&n),n!=-1)
    {
        int x,m;
        memset(g,0,sizeof(g));
        memset(G,0,sizeof(G));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",w+i);
            scanf("%d",&m);
            for (int j=0;j<m;j++)
            {
                scanf("%d",&x);
                G[i][x]=1;
                g[i][x]=1;
            }
        }


        if (loop())
        {
            puts("winnable");
        }
        else
        {
            puts("hopeless");
        }

    }

    return 0;
}

