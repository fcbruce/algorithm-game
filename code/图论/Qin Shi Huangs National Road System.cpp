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
#define maxm
#define maxn 1007

using namespace std;

double G[maxn][maxn];
double maxcost[maxn][maxn];
double mincost[maxn];
bool vis[maxn];
int p[maxn];

struct __city
{
    int x,y,p;
}city[maxn];

int n;

double prim()
{
    memset(vis,0,sizeof vis);
    for (int i=0;i<n;i++) p[i]=i;
    mincost[0]=0;
    double res=0;

    for (;;)
    {
        int v=-1;
        for (int i=0;i<n;i++)
            if (!vis[i] && (v==-1 ||  mincost[i]<mincost[v]))  v=i;

        if (v==-1)  break;

        res+=mincost[v];
        vis[v]=true;

        for (int i=0;i<n;i++)
        {
            if (!vis[i] && G[v][i]<mincost[i])
            {
                p[i]=v;
                mincost[i]=G[v][i];
            }
            if (vis[i] && i!=v)
                    maxcost[v][i]=maxcost[i][v]=max(maxcost[i][p[v]],G[p[v]][v]);
//                    maxcost[v][i]=maxcost[i][v]=max(maxcost[i][p[v]],mincost[v]);
        }
    }

    return res;
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
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d %d",&city[i].x,&city[i].y,&city[i].p);
            for (int j=0;j<i;j++)
            {
                maxcost[i][j]=maxcost[j][i]=0;
                G[i][j]=G[j][i]=sqrt((double)sqr(city[i].x-city[j].x)+sqr(city[i].y-city[j].y));
            }
            G[i][i]=maxcost[i][i]=0;
            mincost[i]=(double)INF;
        }

        double res=prim();
        double ans=0;

        for (int i=0;i<n;i++)
            for (int j=0;j<i;j++)
                ans=max(ans,(city[i].p+city[j].p)/(res-maxcost[i][j]));

        printf("%.2f\n",ans);
    }

    return 0;
}
