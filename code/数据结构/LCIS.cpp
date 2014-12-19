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

int llen[maxn<<2],rlen[maxn<<2],mlen[maxn<<2],lv[maxn<<2],rv[maxn<<2];

inline void pushup(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;

    if (llen[lc]==m-l && rv[lc]<lv[rc]) llen[k]=llen[lc]+llen[rc];  else llen[k]=llen[lc];
    if (rlen[rc]==r-m && lv[rc]>rv[lc]) rlen[k]=rlen[rc]+rlen[lc];  else rlen[k]=rlen[rc];

    lv[k]=lv[lc];rv[k]=rv[rc];

    mlen[k]=0;
    if (rv[lc]<lv[rc])  mlen[k]=rlen[lc]+llen[rc];
    mlen[k]=max(mlen[k],max(mlen[lc],mlen[rc]));
}

void update(int p,int v,int k,int l,int r)
{
    if (r-l==1)
    {
        lv[k]=rv[k]=v;
        llen[k]=rlen[k]=mlen[k]=1;
    }
    else
    {
        int lc=k*2+1,rc=k*2+2,m=l+r>>1;
        if (p<m)    update(p,v,lc,l,m); else    update(p,v,rc,m,r);
        pushup(k,l,r);
    }
}

int query(int a,int b,int k,int l,int r)
{
    if (a<=l && r<=b)
        return mlen[k];

    int lc=k*2+1,rc=k*2+2,m=l+r>>1;
    int res=0;
    if (a<m)    res=max(res,query(a,b,lc,l,m));
    if (b>m)    res=max(res,query(a,b,rc,m,r));

    if (rv[lc]<lv[rc])
    {
        res=max(res,min(b,m+llen[rc])-max(a,m-rlen[lc]));
    }

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m,v,a,b;
    char op;
    scanf("%d",&T_T);

    while (T_T--)
    {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&v);
            update(i,v,0,0,n);
        }

        while (m--)
        {
            scanf("%1s %d %d",&op,&a,&b);
            if (op=='U')
            {
                update(a,b,0,0,n);
            }
            else
            {
                printf("%d\n",query(a,b+1,0,0,n));
            }
        }
    }


    return 0;
}
