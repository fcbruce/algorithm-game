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
#define mm 20007
#define nn 10007

using namespace std;

int n,m;
int fir[nn],u[mm<<1],v[mm<<1],nex[mm<<1];
int q[mm<<2];
bool inq[nn];
int d[nn];
int f,r;
int inc[nn];

bool SPFA(int _u)
{
    memset(inc,0,sizeof inc);
    memset(inq,0,sizeof inq);
    memset(d,-1,sizeof d);
    f=0;r=-1;
    q[++r]=_u;
    inc[_u]++;
    inq[_u]=true;

    while (f<=r)
    {
        int x=q[f++];
        inq[x]=false;
        for (int e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]<d[u[e]]+1)
            {
                d[v[e]]=d[u[e]]+1;
                if (!inq[v[e]])
                {
                    q[++r]=v[e];
                    inq[v[e]]=true;
                    inc[v[e]]++;
                    if (inc[v[e]]>n)    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d %d",&n,&m))
    {
        memset(fir,-1,sizeof fir);
//        memset(_hash,-1,sizeof _hash);
        int ppc=0;
        int x,y;
        for (int e=1;e<=m;e++)
        {
//            scanf("%d %d",&y,&x);
//            if (_hash[x]==-1)   u[e]=_hash[x]=++ppc;    else    u[e]=_hash[x];
//            if (_hash[y]==-1)   v[e]=_hash[y]=++ppc;    else    v[e]=_hash[y];
            scanf("%d %d",&v[e],&u[e]);
            nex[e]=fir[u[e]];
            fir[u[e]]=e;
        }


        for (int i=1;i<=n;i++)
        {

            ++m;
            u[m]=0;v[m]=i;
            nex[m]=fir[0];
            fir[0]=m;

        }


        if (SPFA(0))
        {
            puts("-1");
        }
        else
        {
            int res=0;
            for (int i=1;i<=n;i++)
                res+=d[i];
            res+=888*n;
            printf("%d\n",res);
        }


    }

    return 0;
}
