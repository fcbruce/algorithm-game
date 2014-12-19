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
#define maxn 100007

using namespace std;

int XOR[maxn<<2],setv[maxn<<2],lm1[maxn<<2],rm1[maxn<<2],lm0[maxn<<2],rm0[maxn<<2],sum[maxn<<2],msum1[maxn<<2],msum0[maxn<<2];

inline void SWAP(int k,int l,int r)
{
    swap(lm1[k],lm0[k]);swap(rm1[k],rm0[k]);swap(msum1[k],msum0[k]);sum[k]=r-l-sum[k];
}

inline void pushup(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;

    sum[k]=sum[lc]+sum[rc];

    if (lm1[lc]==m-l)   lm1[k]=lm1[lc]+lm1[rc]; else    lm1[k]=lm1[lc];
    if (rm1[rc]==r-m)   rm1[k]=rm1[rc]+rm1[lc]; else    rm1[k]=rm1[rc];
    msum1[k]=max(rm1[lc]+lm1[rc],max(msum1[lc],msum1[rc]));

    if (lm0[lc]==m-l)   lm0[k]=lm0[lc]+lm0[rc]; else    lm0[k]=lm0[lc];
    if (rm0[rc]==r-m)   rm0[k]=rm0[rc]+rm0[lc]; else    rm0[k]=rm0[rc];
    msum0[k]=max(rm0[lc]+lm0[rc],max(msum0[lc],msum0[rc]));

}

inline void pushdown(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;
    if (setv[k]!=-1)
    {
        setv[lc]=setv[rc]=setv[k];
        XOR[lc]=XOR[rc]=0;

        lm1[lc]=rm1[lc]=msum1[lc]=sum[lc]=setv[k]?m-l:0;
        lm0[lc]=rm0[lc]=msum0[lc]=setv[k]?0:m-l;

        lm1[rc]=rm1[rc]=msum1[rc]=sum[rc]=setv[k]?r-m:0;
        lm0[rc]=rm0[rc]=msum0[rc]=setv[k]?0:r-m;

        setv[k]=-1;
    }

    if (XOR[k])
    {
        if (setv[lc]!=-1)   setv[lc]^=1;    else    XOR[lc]^=1;
        if (setv[rc]!=-1)   setv[rc]^=1;    else    XOR[rc]^=1;
        SWAP(lc,l,m);SWAP(rc,m,r);
        XOR[k]=0;
    }
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        setv[k]=v;
        lm1[k]=rm1[k]=msum1[k]=sum[k]=v?r-l:0;
        lm0[k]=rm0[k]=msum0[k]=v?0:r-l;
        XOR[k]=0;
    }
    else
    {
        pushdown(k,l,r);
        int m=l+r>>1;
        update(a,b,v,k*2+1,l,m);
        update(a,b,v,k*2+2,m,r);
        pushup(k,l,r);
    }
}

void change(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        if (setv[k]!=-1)
            setv[k]^=1;
        else
            XOR[k]^=1;

        SWAP(k,l,r);
    }
    else
    {
        pushdown(k,l,r);
        int m=l+r>>1;
        change(a,b,k*2+1,l,m);
        change(a,b,k*2+2,m,r);
        pushup(k,l,r);
    }
}

int query_sum(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b) return sum[k];

    if (r-l!=1) pushdown(k,l,r);

    int m=l+r>>1,v1=0,v2=0;

    v1=query_sum(a,b,k*2+1,l,m);
    v2=query_sum(a,b,k*2+2,m,r);

    return v1+v2;
}

int query_lc1(itn a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)   return msum1[k];

    if (r-l!=1) pushdown(k,l,r);

    int m=l+r>>1,v1=0,v2=0,v3=0;

    v1=query_lc1(a,b,k*2+1,l,m);
    v2=query_lc1(a,b,k*2+2,m,r);
    v3=min(b,m+lm1[k*2+2])-max(a,m-rm1[k*2+1]);

    return max(v3,max(v1,v2));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m,x,a,b,op;
    scanf("%d",&T_T);

    while (T_T--)
    {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            update(i,i+1,x,0,0,n);
        }

        while (m--)
        {
            scanf("%d %d %d",&op,&a,&b);

            if (op==0)
            {
                update(a,b+1,0,0,0,n);
                continue;
            }

            if (op==1)
            {
                update(a,b+1,1,0,0,n);
                continue;
            }

            if (op==2)
            {
                change(a,b+1,0,0,n);
                continue;
            }

            if (op==3)
            {
                printf("%d\n",query_sum(a,b+1,0,0,n));
                continue;
            }

            if (op==4)
            {
                printf("%d\n",query_lc1(a,b+1,0,0,n));
                continue;
            }
        }
    }

    return 0;
}
