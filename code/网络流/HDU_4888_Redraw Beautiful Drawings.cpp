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
#define maxm 400007
#define maxn 1007

using namespace std;


int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int lv[maxn],iter[maxn],q[maxn];

void add_edge(int _u,int _v,int _w)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(int s)
{
    int f,r;
    memset(lv,-1,sizeof lv);
    q[f=r=0]=s;
    lv[s]=0;
    while (f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if (cap[e]>flow[e] && lv[v[e]]<0)
            {
                lv[v[e]]=lv[u[e]]+1;
                q[++r]=v[e];
            }
        }
    }
}

int dinic_dfs(int _u,int t,int _f)
{
    if (_u==t)  return _f;
    for (int &e=iter[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
        {
            int _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
            if (_d>0)
            {
                flow[e]+=_d;
                flow[e^1]-=_d;
                return _d;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t)
{
    int total_flow=0;
    memset(flow,0,sizeof flow);

    for (;;)
    {
        dinic_bfs(s);
        if (lv[t]<0) return total_flow;

        memcpy(iter,fir,sizeof fir);
        int _f;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;

    }

    return total_flow;
}

int vis[maxn];
bool vise[maxm];

//bool dfs(int _u,int last)
//{
//    vis[_u]=-1;
//    printf("%d\n",_u);
//    for (int e=fir[_u];~e;e=nex[e])
//    {
////        printf("%d --> %d  cap=%d  flow=%d\n",u[e],v[e],cap[e],flow[e]);
////        printf("e=%d last=%d\n",e,last);
////        printf("bool=%d\n",(_u!=s && (e==(last^1) || cap[e]==flow[e])));
//        if (e==(last^1) || cap[e]==flow[e]) continue;
//        printf("%d --> %d  cap=%d  flow=%d\n",u[e],v[e],cap[e],flow[e]);
////        printf("this %d\n",v[e]);
////        if (vis[v[e]]==1) continue;
//        if (vis[v[e]]==-1) return false;
//
//        if (!vis[v[e]] && !dfs(v[e],e)) return false;
//    }
//
//    vis[_u]=1;
//
//    return true;
//}

bool dfs(int _u,int last)
{
    vis[_u]=-1;
    if (~last) vise[last]=1;
//    printf("%d\n",_u);
    for (int e=fir[_u];~e;e=nex[e])
    {
//        printf("%d --> %d  cap=%d  flow=%d\n",u[e],v[e],cap[e],flow[e]);
//        printf("e=%d last=%d\n",e,last);
//        printf("bool=%d\n",(_u!=s && (e==(last^1) || cap[e]==flow[e])));
        if (vise[e] || e==(last^1) || cap[e]==flow[e]) continue;
//        printf("%d --> %d  cap=%d  flow=%d\n",u[e],v[e],cap[e],flow[e]);
//        printf("this %d\n",v[e]);
//        if (vis[v[e]]==1) continue;
        if (vis[v[e]]==-1) return false;

        if (!vis[v[e]] && !dfs(v[e],e)) return false;
    }

    vis[_u]=0;

    return true;
}


int Matrix[404][404];

void construct_Matrix_And_Print(int n,int m)
{
    for (int e=0;e<e_max;e++)
    {
        if (u[e]<=n && u[e]>0 && v[e]>n && v[e]<=n+m)
            Matrix[u[e]][v[e]-n]=flow[e];
    }
    puts("Unique");
    for (int i=1;i<=n;i++)
    {
        for (itn j=1;j<=m;j++)
        {
            printf("%d",Matrix[i][j]);
            if (j==m)
                putchar('\n');
            else
                putchar(' ');
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
        freopen("/home/fcbruce/文档/code/t1","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m,k;

    while (~scanf("%d %d %d",&n,&m,&k))
    {
        int s=0,t=n+m+1,_w,r=0,c=0;
        e_max=0;
        memset(fir,-1,sizeof fir);

        for (int i=1;i<=n;i++)
        {
            scanf("%d",&_w);
            add_edge(s,i,_w);
            r+=_w;
        }

        for (int i=n+1;i<=n+m;i++)
        {
            scanf("%d",&_w);
            add_edge(i,t,_w);
            c+=_w;
        }

        for (int i=1;i<=n;i++)
            for (int j=n+1;j<=n+m;j++)
                add_edge(i,j,k);

        if (r==c && max_flow(s,t)==r)
        {
            memset(vis,0,sizeof vis);
            memset(vise,0,sizeof vise);
            bool flag=true;
            for (int i=0;i<=n+m;i++)
            {
                if (!vis[i])
                if (!dfs(i,-1))
                {
                    flag=false;
                    break;
                }
            }
            if (flag)
                construct_Matrix_And_Print(n,m);
            else
                puts("Not Unique");
        }
        else
            puts("Impossible");

//        puts("");
    }

    return 0;
}
