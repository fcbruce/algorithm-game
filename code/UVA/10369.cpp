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
#define maxm 507*507
#define maxn 507

using namespace std;

struct edge
{
    int u,v;
    double w;
    bool operator < (const edge &e)const
    {
        return w<e.w;
    }
}e[maxm];

struct point
{
    int x,y;
}pp[maxn];

int pre[maxn];

int root(int u)
{
    if (u==pre[u])  return u;
    return pre[u]=root(pre[u]);
}

bool same(int u,int v)
{
    return root(u)==root(v);
}

void _merge(int u,int v)
{
    pre[root(u)]=root(v);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,e_max,s,p;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d %d",&s,&p);
        e_max=0;
        for (int i=0;i<p;i++)
        {
            scanf("%d %d",&pp[i].x,&pp[i].y);
            for (int j=0;j<i;j++)
            {
                e[e_max].u=i;
                e[e_max].v=j;
                e[e_max].w=sqrt(sqr(pp[i].x-pp[j].x)+sqr(pp[i].y-pp[j].y));
                e_max++;
            }
        }

        sort(e,e+e_max);
        for (int i=0;i<p;i++)pre[i]=i;

        for (int i=0;i<e_max;i++)
        {
            if (same(e[i].u,e[i].v)) continue;
            _merge(e[i].u,e[i].v);
            p--;
            if (p==s)
            {
                printf("%.2f\n",e[i].w);
                break;
            }
        }
    }



    return 0;
}
