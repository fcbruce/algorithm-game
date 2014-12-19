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
#define maxm 107
#define maxn 107

using namespace std;

int fir[maxn],d[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
bool inq[maxm];
int q[sqr(maxn)];
int inc[maxn];
itn n,m,f,r;

bool SPFA(int _u)
{
    memset(inq,0,sizeof inq);
    memset(d,0x3f,sizeof d);
    memset(inc,0,sizeof inc);
    d[_u]=0;
    q[f=r=0]=_u;
    inc[_u]++;
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
                    inc[v[e]]++;
                    if (inc[v[e]]>n+2)    return true;
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

    while (scanf("%d",&n),n)
    {
        scanf("%d",&m);
        int _u,_v,_w;
        char op;
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            scanf("%d %d %ct %d",&_u,&_v,&op,&_w);
            if (op=='l')
            {
                u[i]=_u-1;v[i]=_u+_v;w[i]=_w-1;
                nex[i]=fir[_u-1];
                fir[_u-1]=i;
            }
            else
            {
                u[i]=_u+_v;v[i]=_u-1;w[i]=-_w-1;
                nex[i]=fir[_u+_v];
                fir[_u+_v]=i;
            }
        }
        for (int i=0;i<=n;i++)
        {
            u[m]=n+1;v[m]=i;w[m]=0;
            nex[m]=fir[n+1];
            fir[n+1]=m;
            m++;
        }

        if (!SPFA(n+1))
        {
            puts("lamentable kingdom");
        }
        else
        {
            puts("successful conspiracy");
        }
    }

    return 0;
}
