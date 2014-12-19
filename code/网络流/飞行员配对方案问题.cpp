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
#define maxm 100007
#define maxn 107

using namespace std;

int n,m;
int e_max;
int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm],rev[maxm];
int q[maxm],f,r;
int p[maxn],d[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d %d",&m,&n))
    {
        int _u,_v;
        memset(fir,-1,sizeof fir);
        e_max=0;
        while (scanf("%d %d",&_u,&_v),~_u)
        {
            int e=e_max++;
            u[e]=_u;v[e]=_v;cap[e]=1;flow[e]=0;nex[e]=fir[_u];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=_v;v[e]=_u;cap[e]=flow[e]=0;nex[e]=fir[_v];fir[u[e]]=e;rev[e]=e-1;
        }
        for (int i=1;i<=m;i++)
        {
            int e=e_max++;
            u[e]=0;v[e]=i;cap[e]=1;flow[e]=0;nex[e]=fir[0];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=i;v[e]=0;cap[e]=flow[e]=0;nex[e]=fir[i];fir[u[e]]=e;rev[e]=e-1;
        }
        for (int i=m+1;i<=n;i++)
        {
            int e=e_max++;
            u[e]=i;v[e]=n+1;cap[e]=1;flow[e]=0;nex[e]=fir[i];fir[u[e]]=e;rev[e]=e+1;
            e=e_max++;
            u[e]=n+1;v[e]=i;cap[e]=flow[e]=0;nex[e]=fir[n+1];fir[u[e]]=e;rev[e]=e-1;
        }

        int s=0,t=n+1;
        int cnt=0;
        while (true)
        {
            f=0;r=-1;
            memset(d,0,sizeof d);
            d[s]=INF;
            q[++r]=s;
            int last,las=-1;
            while (f<=r)
            {
                int x=q[f++];
                last=-1;

                for (int e=fir[x];~e;e=nex[e])  if (!d[v[e]] && cap[e]>flow[e])
                {
                    q[++r]=v[e];
                    p[v[e]]=e;
                    d[v[e]]=min(d[u[e]],cap[e]-flow[e]);
                }
            }

            if (d[t]==0)    break;
            cnt+=d[t];

            for (int e=p[t];;e=p[u[e]])
            {
                flow[e]+=d[t];
                flow[rev[e]]-=d[t];

                if (u[e]==0)    break;
            }


        }

        printf("%d\n",cnt);

//        for (int e=0;e<e_max;e++)
//        {
//            if (u[e]>0 && u[e]<=m && v[e]>m && v[e]<=n)
//                if (flow[e]==1)
//                    printf("%d %d\n",u[e],v[e]);
//        }
    }



    return 0;
}
