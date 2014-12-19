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
#define maxm 210007
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int lv[maxn],q[maxn],iter[maxn];

void add_edge(int _u,int _v,int _w)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_w;nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(int s)
{
    int f,r;
    memset(lv,-1,sizeof lv);
    lv[s]=0;
    q[f=r=0]=s;
    while (f<=r)
    {
        int x=q[f++];
        for (int e=fir[x];~e;e=nex[e])
        {
            if(cap[e]>flow[e] && lv[v[e]]<0)
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
    memset(flow,0,sizeof flow);
    int total_flow=0;

    for (;;)
    {
        dinic_bfs(s);
        if (lv[t]<0)    return total_flow;

        memcpy(iter,fir,sizeof fir);

        int _f;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;
    }
    return total_flow;
}

struct node
{
    int in[10],out[10];
    int in1,out0;
}a[55];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int p,n,s,t,_w;

    e_max=0;
    memset(fir,-1,sizeof fir);
    scanf("%d %d",&p,&n);
    s=0;t=n+n+1;

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&_w);
        add_edge(i,i+n,_w);
        a[i].in1=0;
        for (int j=0;j<p;j++)
        {
            scanf("%d",&a[i].in[j]);
            if (a[i].in[j]==1)  a[i].in1++;
        }
        a[i].out0=0;
        for (int j=0;j<p;j++)
        {
            scanf("%d",&a[i].out[j]);
            if (a[i].out[j]==0)  a[i].out0++;
        }

        if (a[i].in1==0)    add_edge(s,i,INF);
        if (a[i].out0==0)    add_edge(i+n,t,INF);

        for (int j=1;j<i;j++)
        {
            if (a[j].in1!=0 && a[i].out0!=0)
            {
                bool flag=true;
                for (int k=0;flag && k<p;k++)
                {
                    if (a[i].out[k]+a[j].in[k]==1)
                        flag=false;
                }
                if (flag)
                    add_edge(i+n,j,INF);
            }
            if (a[i].in1!=0 && a[j].out0!=0)
            {
                bool flag=true;
                for (int k=0;flag && k<p;k++)
                {
                    if (a[j].out[k]+a[i].in[k]==1)
                        flag=false;
                }
                if (flag)
                    add_edge(j+n,i,INF);
            }
        }
    }

    printf("%d ",max_flow(s,t));

    int m=0;
    for (int e=0;e<e_max;e++)
    {
        if (flow[e]<=0 || u[e]==s || v[e]==t || v[e]-u[e]==n) continue;
        u[m]=u[e]>n?u[e]-n:u[e];
        v[m]=v[e];
        flow[m]=flow[e];
        m++;
    }

    printf("%d\n",m);
    for (int e=0;e<m;e++)
        printf("%d %d %d\n",u[e],v[e],flow[e]);

    return 0;
}
