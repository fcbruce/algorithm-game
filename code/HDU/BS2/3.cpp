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
#define maxm 100000
#define maxn 1007

using namespace std;

int fir[maxn];
itn u[maxm],v[maxm],w[maxm],nex[maxm];
itn e_max;
itn d[maxn];
int q[maxm<<2];
itn f,r;
bool inq[maxn];

struct pp
{
    int x,y;
}a[1007];

void add_edge(itn _u,int _v,int _w)
{
    int e;
    e=e_max++;
    u[e]=_u;v[e]=_v;w[e]=_w;
    nex[e]=fir[_u];fir[_u]=e;
}

int SPFA(itn s,int t)
{
    memset(d,0x3f,sizeof d);
    d[s]=0;
    q[f=r=0]=s;
    memset(inq,0,sizeof inq);

    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];~e;e=nex[e])
        {
            if (d[v[e]]>d[u[e]]+w[e])
            {
                d[v[e]]=d[u[e]]+w[e];
                if (!inq[v[e]])
                {
                    inq[v[e]]=true;
                    q[++r]=v[e];
                }
            }
        }
    }

    return d[t];
}

double Dis(int i,int j)
{
    return sqrt(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE
    itn T_T,n,m;
    double dis;

    scanf("%d",&T_T);
    while (T_T--)
    {
        e_max=0;
        memset(fir,-1,sizeof fir);
        scanf("%d %lf",&n,&dis);
        scanf("%d %d",&a[0].x,&a[0].y);
        scanf("%d %d",&a[n+1].x,&a[n+1].y);
        for (itn i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
        }

        for (itn i=0;i<=n+1;i++)
        {
            for (itn j=i+1;j<=n+1;j++)
            {
                if (Dis(i,j)<dis || fabs(Dis(i,j)-dis)<=1e-8){
//                        printf("%d %d\n",i,j);
                    add_edge(i,j,1),add_edge(j,i,1);
                }
            }
        }



        int s=0,t=n+1;

        int ans=SPFA(s,t);
        if (ans!=INF)
            printf("%d\n",ans-1);
        else
            puts("impossible");
    }


    return 0;
}
