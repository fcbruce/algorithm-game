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
#define maxm 40007<<1
#define maxn 40007

using namespace std;

int fir[maxn],d[maxn];
int u[maxm],v[maxm],nex[maxm],w[maxm];
bool inq[maxn];
int q[maxm<<1];
itn f,r;
int n,m;

void SPFA(int _u)
{
    memset(d,0x3f,sizeof d);
    memset(inq,0,sizeof inq);
    d[_u]=0;
    q[f=r=0]=_u;
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
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d %d",&n,&m))
    {
        memset(fir,-1,sizeof fir);
        for (int i=0;i<m;i++)
        {
            int _u,_v,_w;
            char ch;
            scanf("%d %d %d %c",&_u,&_v,&_w,&ch);
            u[i]=_u;v[i]=_v;w[i]=_w;
            nex[i]=fir[_u];
            fir[_u]=i;
            u[i+m]=_v;v[i+m]=_u;w[i+m]=_w;
            nex[i+m]=fir[_v];
            fir[_v]=i+m;
        }

        SPFA(1);
        int MAXV=-1;
        for (int i=1;i<=n;i++)  if (MAXV==-1 || d[MAXV]<d[i])   MAXV=i;
        SPFA(MAXV);
        MAXV=-1;
        for (int i=1;i<=n;i++)  if (MAXV==-1 || d[MAXV]<d[i])   MAXV=i;
        printf("%d\n",d[MAXV]);

    }

    return 0;
}
