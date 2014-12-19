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
#define maxm 30007
#define maxn 1007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
int lv[maxn],iter[maxn],q[maxn];
map<string,int> MAP;

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

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    scanf("%d",&T_T);

    while (T_T--)
    {
        MAP.clear();
        int n,s=0,t=2,m,k,_u,_v;
        char s1[50],s2[50],str[50];
        e_max=0;
        memset(fir,-1,sizeof fir);
        int cnt=2;

        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s1);
//            putchar(ch1);
            if (MAP[string(s1)]==0) _u=MAP[string(s1)]=cnt++;   else _u=MAP[string(s1)];
            add_edge(_u<<1,t,1);
        }

        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%s %s",str,s1);
            if (MAP[string(s1)]==0) _u=MAP[string(s1)]=cnt++;   else _u=MAP[string(s1)];
            add_edge(s,_u<<1|1,1);
            add_edge(_u<<1|1,_u<<1,1);
        }

        scanf("%d",&k);
        for (int i=0;i<k;i++)
        {
            scanf("%s %s",s1,s2);
            if (MAP[string(s1)]==0) _u=MAP[string(s1)]=cnt++;   else _u=MAP[string(s1)];
            if (MAP[string(s2)]==0) _v=MAP[string(s2)]=cnt++;   else _v=MAP[string(s2)];
//            printf("ch1=%c ch2=%c\n",ch1,ch2);
//            add_edge(_u<<1|1,_v<<1,1);
            add_edge(_u<<1,_v<<1,INF);
        }

        printf("%d\n",m-max_flow(s,t));

        if (T_T)    puts("");

    }

    return 0;
}
