#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
#define itn int
#define maxn 1007
#define maxm 2333333
#define INF 0x3f3f3f3f
using namespace std;


int a[maxn],b[maxn];
int fir[maxn];
itn u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;
itn q[maxn<<2];

itn lv[maxn],iter[maxn];

void add_edge(int _u,int _v,int _w)
{

    int e=e_max++;
    u[e]=_u;v[e]=_v;cap[e]=_w;
    nex[e]=fir[u[e]];fir[u[e]]=e;
    e=e_max++;
    u[e]=_v;v[e]=_u;cap[e]=0;
    nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(itn s)
{
    int f,r;
    lv[s]=0;
    q[f=r=0]=s;

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

int dinic_dfs(int s,int t,int _f)
{
    if (s==t)   return _f;

    for (int &e=iter[s];~e;e=nex[e])
    {
        if (cap[e]>flow[e] && lv[s]<lv[v[e]])
        {
            int _d=dinic_dfs(v[e],t,min(cap[e]-flow[e],_f));
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


itn max_flow(int s,int t)
{
    int total_flow=0;

    memset(flow,0,sizeof flow);
    for (;;)
    {
        memset(lv,-1,sizeof lv);
        dinic_bfs(s);

        if (lv[t]==-1)  break;

        memcpy(iter,fir,sizeof fir);

        itn _f=0;
        while ((_f=dinic_dfs(s,t,INF))>0)
            total_flow+=_f;

    }

    return total_flow;

}

int main()
{
    int n,m;
    itn T_T,cas=0;
    scanf("%d",&T_T);

    while(T_T--)
    {
        printf("Case #%d: ",++cas);
        scanf("%d%d",&n,&m);
        itn s=0,t=n+m+1;
        itn sr=0,sc=0;
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            add_edge(s,i,a[i]);
            sr+=a[i];
        }

        for (int i=1;i<=m;i++)
        {
            scanf("%d",b+i);
            add_edge(i+n,t,b[i]);
        }

        for (int i=1,k,p;i<=n;i++)
        {
            scanf("%d",&k);
            for (int j=0;j<k;j++)
            {
                scanf("%d",&p);
                p++;
                add_edge(i,p+n,INF);
            }

        }

        int x;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&x);
                if (x)
                add_edge(i+n,j+n,INF);
            }
        }

        int res=sr-max_flow(s,t);
        
        printf("%d\n",res);
    }


    return 0;
}
