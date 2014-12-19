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
#define maxm
#define maxn

using namespace std;

struct gr
{
    int n,s,t;

}a[10001];

int add[24*60*4+4];
itn maxv[24*60*4+4];

void pushdown(int k,int l,int r)
{
    if (add[k])
    {
        add[k*2+1]+=add[k];
        add[k*2+2]+=add[k];
        maxv[k*2+1]+=add[k];
        maxv[k*2+2]+=add[k];
        add[k]=0;
    }
}

void pushup(int k,int l,int r)
{
    maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
    maxv[k]+=add[k];
}

void update(itn a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        add[k]+=v;
        maxv[k]+=v;
    }
    else
    {
        pushdown(k,l,r);
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
        pushup(k,l,r);
    }

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    scanf("%d",&T_T);
    itn n,s1,s2,m1,m2;

    while (T_T--)
    {
        scanf("%d",&n);
        memset(maxv,0,sizeof maxv);
        memset(add,0,sizeof add);
        for (int i=0;i<n;i++)
        {
            scanf("%d ",&a[i].n);
            scanf("%d:%d %d:%d",&s1,&m1,&s2,&m2);
            a[i].s=s1*60+m1;a[i].t=s2*60+m2;
            update(s1*60+m1,s2*60+m2,a[i].n,0,0,24*60+1);
        }

        printf("%d\n",maxv[0]);




    }

    return 0;
}
