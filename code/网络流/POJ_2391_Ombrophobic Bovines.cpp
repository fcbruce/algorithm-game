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
#define maxm 2000007
#define maxn 407

using namespace std;

long long G[maxn][maxn];//,rest[maxn],save[maxn];
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;

int fir[maxn],fir_temp[maxn];
int u[maxm],v[maxm],nex[maxm];
int cap[maxm],flow[maxm];
int e_max,e_temp;
int lv[maxn],iter[maxn],q[maxn];

inline int ReadInt()
{
    int flag=0;
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}

inline long long ReadLL()
{
    int flag=0;
    char ch = getchar();
    long long data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}


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

void dinic_bfs(int s,int t)
{
    int f,r;
    memset(lv,-1,sizeof lv);
    lv[s]=0;
    q[f=r=0]=s;
    while (f<=r)
    {
        int x=q[f++];
        for (itn e=fir[x];~e;e=nex[e])
        {
            if (cap[e]>flow[e] && lv[v[e]]<0)
            {
                lv[v[e]]=lv[u[e]]+1;
                q[++r]=v[e];
                if (v[e]==t)    return ;
            }
        }
    }
}

int  dinic_dfs(int _u,int t,int _f)
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
    memset(flow,0,sizeof flow);
    int total_flow=0;

    for (;;)
    {
        dinic_bfs(s,t);

        if (lv[t]<0)    return  total_flow;

        memcpy(iter,fir,sizeof iter);

        int _f;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;
    }

    return total_flow;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,s,t,_u,_v,_w;
    int total_cow=0,total_cap=0;
    long long l,r;
    memset(fir,-1,sizeof fir);
    scanf("%d%d",&n,&m);
    s=0;t=n+n+1;
    e_max=0;
    for (int i=1;i<=n;i++)
    {
//        scanf("%d",&_w);
        _w=ReadInt();add_edge(s,i,_w);total_cow+=_w;
//        scanf("%d",&_w);
        _w=ReadInt();add_edge(i+n,t,_w);total_cap+=_w;
    }

    if (total_cow>total_cap)
    {
        puts("-1");
        return 0;
    }

    memset(G,0x3f,sizeof G);
    for (int i=1;i<=n;i++)  {G[i][i]=0;add_edge(i,i+n,INF);}

    l=r=0;
    for (int i=0;i<m;i++)
    {
//        scanf("%d %d %d",&_u,&_v,&_w);
        _u=ReadInt();_v=ReadInt();_w=ReadLL();
        G[_u][_v]=G[_v][_u]=min((long long )_w,G[_u][_v]);

    }

    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (G[i][j]!=INFLL) r=max(r,G[i][j]);

    memcpy(fir_temp,fir,sizeof fir);
    e_temp=e_max;
    long long ans=-1;
    while (l<=r)
    {
        long long mid=l+r>>1;
        memcpy(fir,fir_temp,sizeof fir);
        e_max=e_temp;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (G[i][j]<=mid)    {add_edge(i,j+n,INF);add_edge(j,i+n,INF);}

        if (max_flow(s,t)==total_cow)
        {
            r=mid-1;
            ans=mid;
        }
        else
        {
            l=mid+1;
        }
    }

    printf("%I64d\n",ans);


    return 0;
}
