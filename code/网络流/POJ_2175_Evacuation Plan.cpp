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
#define maxm (65536)
#define maxn (202)

using namespace std;

struct __point
{
    int x,y,p;
}b[101],sh[101];
int n,m;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],cost[maxm],nex[maxm];
int e_max;
int q[maxn],d[maxn],prev[maxn],cnt[maxn];
bool inq[maxn];

int G[101][101];
int shelter[101];
bool vis[maxn];

void add_edge(int _u,int _v,int _cap,int _cost,int _f)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_cap;cost[e]=_cost;flow[e]=_f;
    nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;cost[e]=-_cost;flow[e]=-_f;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

int negative_loop(int s,int t)
{
    int f,r,top=-1;
    f=0;r=-1;

    memset(cnt,0,sizeof cnt);
    memset(d,0,sizeof d);
    memset(inq,1,sizeof inq);//inq是bool类型的数组，每个元素占1字节，所以可以这样
    memset(prev,-1,sizeof prev);
    for (int i=s;i<=t;i++)
        q[++r]=i;

    while (f<=r)
    {
        int x=q[r--];//栈式写法，r--改成f++就是队列了，队列要将数组扩大。
        inq[x]=false;
        for (int e=fir[x];~e;e=nex[e])
        {
            if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+cost[e])
            {
                d[v[e]]=d[u[e]]+cost[e];
                prev[v[e]]=e;
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                    cnt[v[e]]++;
                    if (cnt[v[e]]>t-s+1)    return v[e];
                    //如过不想判断边界，就把这个值调大些，因为如果没有负环就不会进队/栈那么多次，如果有负环，就会无限循环下去
                }
            }
        }
    }

    return -1;
}


inline int __cost(const __point &p1,const __point &p2)
{
    return abs(p1.x-p2.x)+abs(p1.y-p2.y)+1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int p;
    int s,t;
    scanf("%d%d",&n,&m);
    s=0;t=n+m+1;
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].p);
        add_edge(s,i+1,b[i].p,0,b[i].p);
    }

    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&sh[i].x,&sh[i].y,&sh[i].p);
    }

    memset(shelter,0,sizeof shelter);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d",&p);
            shelter[j]+=p;
            add_edge(i+1,n+j+1,INF,__cost(b[i],sh[j]),p);
        }
    }

    for (int i=0;i<m;i++)
    {
        add_edge(i+1+n,t,sh[i].p,0,shelter[i]);
    }

    int k=negative_loop(s,t);

    if (k!=-1)
    {
        puts("SUBOPTIMAL");
        memset(vis,0,sizeof vis);

        for (int e=prev[k];!vis[v[e]];e=prev[u[e]])//往前找负环
        {
            vis[v[e]]=true;
            k=v[e];
        }

        for (int e=prev[k];;e=prev[u[e]])//在负环中增广
        {
            flow[e]++;//只要找一个更优的解，+1就行
            flow[e^1]--;
            if (u[e]==k)break;
        }

        for (int e=0;e<e_max;e++)
        {
            if (u[e]>0 && u[e]<=n && v[e]>n && v[e]<=n+m)
                G[u[e]-1][v[e]-n-1]=flow[e];
        }

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (j) putchar(' ');
                printf("%d",G[i][j]);
            }
            putchar('\n');
        }
    }
    else
        puts("OPTIMAL");


    return 0;
}
