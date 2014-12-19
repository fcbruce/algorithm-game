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
#define maxm 9999999
#define maxn 20007

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

void dinic_bfs(int s,int t)
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
                if (v[e]==t)    return;
            }
        }
    }
}

int dinic_dfs(int _u,int t,int _f)
{
    if (_u==t)  return _f;
    int _w=0;
    for (int e=fir[_u];(~e) && _w<_f;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
        {
            int _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
            if (_d>0)
            {
                flow[e]+=_d;
                flow[e^1]-=_d;
                _f-=_d;
                _w+=_d;
                if (!_f) break;
            }

        }
    }

    if (!_w) lv[_u]=-1;
    return _w;
}

int max_flow(int s,int t)
{
    int total_flow=0;
    memset(flow,0,sizeof flow);

    for (;;)
    {
        dinic_bfs(s,t);
        if (lv[t]<0) return total_flow;

//        memcpy(iter,fir,sizeof iter);
        int _f;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;

    }

    return total_flow;
}
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

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,s,t,_u,_v,_w;

    while (~scanf("%d %d",&n,&m)){


    s=0;t=n+1;

    memset(fir,-1,sizeof fir);
    e_max=0;

    for (int i=1;i<=n;i++)
    {
        //scanf("%d",&_w);
        add_edge(s,i,ReadInt());
//        scanf("%d",&_w);
        add_edge(i,t,ReadInt());
    }

    for (int i=0;i<m;i++)
    {
//        scanf("%d %d %d",&_u,&_v,&_w);
        _u=ReadInt();_v=ReadInt();_w=ReadInt();
        add_edge(_u,_v,_w);
        add_edge(_v,_u,_w);
    }

    printf("%d\n",max_flow(s,t));
    }

    return 0;
}
