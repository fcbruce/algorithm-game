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
#define maxm 200007
#define maxn 404

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int iter[maxn],q[maxn],lv[maxn];

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
    while(f<=r)
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
        if (cap[e]>flow[e] && lv[_u]<lv[v[e]])
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
        dinic_bfs(s);
        if (lv[t]<0)    return total_flow;
        memcpy(iter,fir,sizeof iter);
        int _f;

        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;
    }

    return total_flow;
}

int that_edge[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,_u,_v,_w,s,t;

    scanf("%d%d%d",&n,&_u,&_v);
    s=_u+n;t=_v;
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&_w);
            if (!_w) continue;
            if (i==_u && j==_v || i==_v && j==_u)
            {
                printf("NO ANSWER!\n");
                return 0;
            }
            add_edge(i+n,j,INF);
        }
    }

    for (int i=1;i<=n;i++)
    {
        that_edge[i]=e_max;
        add_edge(i,i+n,1);
    }

    int temp=max_flow(s,t);
    bool first=false;
    printf("%d\n",temp);

    for (int i=1;i<=n && temp;i++)
    {
        if (i==s-n || i==t) continue;
        if (!flow[that_edge[i]]) continue;//最小割边一定满流，考虑逆否命题，不满流的边一定不是最小割边
        cap[that_edge[i]]=0;

        int k=max_flow(s,t);
        if (k<temp)
        {
            if (first) putchar(' ');
            first=true;
            printf("%d",i);
        }
        else
            cap[that_edge[i]]=1;
        temp=k;
    }

    putchar('\n');


    return 0;
}
