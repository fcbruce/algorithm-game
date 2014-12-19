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
#define mm

using namespace std;

struct edge
{
    int u,v,w;
    bool operator < (const edge &e)const
    {
        return w<e.w;
    }
}e[15007];

int pre[1007];
bool choose[15007];

int root(int x)
{
    if (x==pre[x])  return x;
    return root(pre[x]);
}

inline bool same(int x,int y)
{
    return root(x)==root(y);
}

inline void intree(int x,int y)
{
    pre[root(x)]=pre[root(y)];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m;

    while (~scanf("%d %d",&n,&m))
    {
        for (int i=0;i<m;i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
            choose[i]=false;
        }

        sort(e,e+m);

        int cnt=0,MAX;

        for (int i=0;i<=n;i++)  pre[i]=i;

        for (int i=0;i<m;i++)
        {
            if (!same(e[i].u,e[i].v))
            {
                intree(e[i].u,e[i].v);
                choose[i]=true;
                cnt++;
                MAX=e[i].w;
            }
        }

        printf("%d\n%d\n",MAX,cnt);
        for (int i=0;i<m;i++)
        {
            if (choose[i])
                printf("%d %d\n",e[i].u,e[i].v);
        }


    }


    return 0;
}
