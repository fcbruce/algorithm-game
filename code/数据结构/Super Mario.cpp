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
#define mm 100007

using namespace std;

int _sum[mm<<2],ans[mm];

struct brick
{
    int p,h;
    bool operator < (const brick &b)const
    {
        return h<b.h;
    }
}b[mm];

struct _query
{
    int l,r,h,id;
    bool operator < (const _query &q)const
    {
        return h<q.h;
    }
}q[mm];

void update(int p,int k,int l ,int r)
{
    //if (p<l && p>=r)    return;

    _sum[k]++;

    if (r-l==1) return ;

    itn m=l+r>>1;
    if (p<m)    update(p,k*2+1,l,m);    else    update(p,k*2+2,m,r);
}

int query(itn a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)   return _sum[k];
    else
    {
        return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
//        freopen("/home/fcbruce/ÎÄµµ/code/t1","w",stdout);
    #endif // ONLINE_JUDGE

    int T_T,n,m,x,_a,_b,h;
    scanf("%d",&T_T);
    for (itn t=1;t<=T_T;t++)
    {

        memset(_sum,0,sizeof _sum);
        printf("Case %d:\n",t);

        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            b[i].p=i;
            b[i].h=x;
        }

        for (itn i=0;i<m;i++)
        {
            scanf("%d %d %d",&_a,&_b,&h);_b++;
            q[i].l=_a;
            q[i].r=_b;
            q[i].h=h;
            q[i].id=i;
        }

        sort(b,b+n);
        sort(q,q+m);

        for (int i=0,j=0;i<m;i++)
        {
            while (j<n && b[j].h<=q[i].h)
            {
                update(b[j].p,0,0,n);
                j++;
            }

            ans[q[i].id]=query(q[i].l,q[i].r,0,0,n);
        }

        for (itn i=0;i<m;i++)
        {
            printf ("%d\n",ans[i]);
        }
    }

    return 0;
}
