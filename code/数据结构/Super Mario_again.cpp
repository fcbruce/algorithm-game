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
#define maxn 100007

using namespace std;

struct brick
{
    int p,h;
    bool operator < (const brick &b)const
    {
        return h<b.h;
    }
}b[maxn];

struct _query
{
    int l,r,h,id;
    bool operator < (const _query &q)const
    {
        return h<q.h;
    }
}q[maxm];

int sum[maxn<<2];
int ans[maxm];

void update(int p,int k,int l,int r)
{
    if (r-l==1) sum[k]=1;
    else
    {
        int m=l+r>>1;
        if (p<m)    update(p,k*2+1,l,m);    else    update(p,k*2+2,m,r);
        sum[k]=sum[k*2+1]+sum[k*2+2];
    }
}

int query(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;
    if (a<=l && r<=b)   return sum[k];
    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m;
    scanf("%d",&T_T);
    for (int T__T=1;T__T<=T_T;T__T++)
    {
        printf("Case %d:\n",T__T);
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i].h);
            b[i].p=i;
        }

        for (int i=0;i<n;i++)
        {
            scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].h);
            q[i].id=i;q[i].r++;
        }

        sort(b,b+n);
        sort(q,q+m);

        memset(sum,0,sizeof sum);

        for (int i=0,j=0;i<m;i++)
        {
            for (;j<n && b[j].h<=q[i].h;j++)
            {
                update(b[j].p,0,0,n);
            }

            ans[q[i].id]=query(q[i].l,q[i].r,0,0,n);
        }

        for (int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}
