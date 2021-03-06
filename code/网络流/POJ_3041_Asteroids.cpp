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
#define maxm 25007
#define maxn 1007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int iter[maxn],lv[maxn],q[maxn];

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
    if (_u==t) return _f;
    for (int &e=iter[_u];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[v[e]]>lv[_u])
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

//int dinic_dfs(int _u,int t,int _f)
//{
//    if (_u==t)  return _f;
//    int _w=0;
//    for (int e=fir[_u];~e;e=nex[e])
//    {
//        if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
//        {
//            int _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
//            if (_d>0)
//            {
//                flow[e]+=_d;
//                flow[e^1]-=_d;
//                _f-=_d;
//                _w+=_d;
//                if (!_f) break;
//            }
//
//        }
//    }
//    return _w;
//}

//int dinic_dfs(int _u,int t,int _f)
//{
//    if (_u==t)  return _f;
//    int _w=0;
//    for (int &e=iter[_u];(~e) && _w<_f;e=nex[e])
//    {
//        if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
//        {
//            int _d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
//            if (_d>0)
//            {
//                flow[e]+=_d;
//                flow[e^1]-=_d;
//                _f-=_d;
//                _w+=_d;
//                if (!_f) break;
//            }
//
//        }
//    }
//    if (!_w) lv[_u]=-1;
//    return _w;
//}

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


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;
    scanf("%d %d",&n,&m);
    memset(fir,-1,sizeof fir);
    e_max=0;
    int s=0,t=n+n+1;
    for (int i=1;i<=n;i++)
        add_edge(s,i,1);
    for (int i=n+1;i<=n+n;i++)
        add_edge(i,t,1);

    for (int i=0,_u,_v;i<m;i++)
    {
        scanf("%d %d",&_u,&_v);
        add_edge(_u,_v+n,1);
    }

    printf("%d\n",max_flow(s,t));


    return 0;
}
