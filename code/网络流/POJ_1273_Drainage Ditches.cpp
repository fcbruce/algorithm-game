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
#define maxm 207<<2
#define maxn 207

using namespace std;

int fir[maxn],d[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],rev[maxm],nex[maxm];
int e_max;
int q[maxm];
int p[maxn];
int n,m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d %d",&n,&m))
    {
        e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<n;i++)
        {
            int e=e_max++;
            scanf("%d %d %d",u+e,v+e,cap+e);
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=v[e-1];v[e]=u[e-1];cap[e]=0;
            nex[e]=fir[u[e]];fir[u[e]]=e;rev[e]=e-1;
        }//建图

        int s=1,t=m,total_flow=0;
        memset(flow,0,sizeof flow);

        for (;;)
        {
            int f,r;
            memset(d,0,sizeof d);
            d[s]=INF;
            q[f=r=0]=s;
            while (f<=r)
            {
                int x=q[f++];
                for (int e=fir[x];~e;e=nex[e])
                {
                    if (!d[v[e]] && cap[e]>flow[e])
                    {
                        d[v[e]]=min(d[u[e]],cap[e]-flow[e]);
                        p[v[e]]=e;
                        q[++r]=v[e];
                    }
                }
            }//BFS找增广路

            if (d[t]==0)    break;//流量为0,无残量

            //更新路径上的流量
            for (int e=p[t];;e=p[u[e]])
            {
                flow[e]+=d[t];
                flow[rev[e]]-=d[t];
                if (u[e]==s)    break;
            }

            total_flow+=d[t];
        }

        printf("%d\n",total_flow);
    }


    return 0;
}
