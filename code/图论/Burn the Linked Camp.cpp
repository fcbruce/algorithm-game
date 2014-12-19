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
#define mm 10007<<1
#define nn 10007

using namespace std;

int n,m;
int fir[nn];
int u[mm],v[mm],w[mm],nex[mm];
int s[nn];
int d[nn];
int inc[nn];
bool inq[nn];
int q[mm<<2];
int f,r;

bool SPFA(int _u)
{
    memset(inq,0,sizeof inq);
    memset(inc,0,sizeof inc);
    f=0;r=-1;
    memset(d,0xcf,sizeof d);
    q[++r]=_u;
    d[_u]=0;
    inc[_u]++;
    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]<d[u[e]]+w[e])
            {
                d[v[e]]=d[u[e]]+w[e];
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                    inc[v[e]]++;
                    if (inc[v[e]]>n)    return  false;
                }
            }
        }
    }

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE
    //printf("%d\n",0xcfcfcfcf);
    while (~scanf("%d %d",&n,&m))
    {
        int e_max=0;
        memset(fir,-1,sizeof fir);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            u[e_max]=i;v[e_max]=i-1;w[e_max]=-x;
            nex[e_max]=fir[i];
            fir[i]=e_max;
            e_max++;
            u[e_max]=i-1;v[e_max]=i;w[e_max]=0;
            nex[e_max]=fir[i-1];
            fir[i-1]=e_max;
            e_max++;
        }
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            u[e_max]=x-1;v[e_max]=y;w[e_max]=z;
            nex[e_max]=fir[x-1];
            fir[x-1]=e_max;
            e_max++;
        }

        if (SPFA(0))
        {
            printf("%d\n",d[n]);
        }
        else
        {
            puts("Bad Estimations");
        }

    }


    return 0;
}
