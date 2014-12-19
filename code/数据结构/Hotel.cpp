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
#define maxn 50005

using namespace std;

int lsum[maxn<<2],rsum[maxn<<2],msum[maxn<<2],cov[maxn<<2];
int n,m;

void pushdown(int k,int l,int r)
{
    if (cov[k]==-1) return ;

    int lc=k*2+1,rc=k*2+2;

    cov[lc]=cov[rc]=cov[k];

    if (cov[k]==0)
    {
        lsum[lc]=rsum[lc]=msum[lc]=(l+r>>1)-l;
        lsum[rc]=rsum[rc]=msum[rc]=r-(l+r>>1);
    }

    if (cov[k]==1)
    {
        lsum[lc]=rsum[lc]=msum[lc]=0;
        lsum[rc]=rsum[rc]=msum[rc]=0;
    }

    cov[k]=-1;

}

void pushup(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;

    if (lsum[lc]==m-l)  lsum[k]=lsum[lc]+lsum[rc];  else    lsum[k]=lsum[lc];
    if (rsum[rc]==r-m)  rsum[k]=rsum[rc]+rsum[lc];  else    rsum[k]=rsum[rc];

    msum[k]=max(rsum[lc]+lsum[rc],max(msum[lc],msum[rc]));
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        cov[k]=v;
        lsum[k]=rsum[k]=msum[k]=v?0:r-l;
        return ;
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

int query(int w,int k,int l,int r)
{
    if (r-l==1) return l;
    pushdown(k,l,r);
    int lc=k*2+1,rc=k*2+2;
    if (msum[lc] >= w)  return query(w,lc,l,l+r>>1);
    if (rsum[lc]+lsum[rc] >= w) return (l+r>>1)-rsum[lc];
    if (msum[rc] >= w)  return query(w,rc,l+r>>1,r);
    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int op,a,len;
    while (~scanf("%d %d",&n,&m))
    {
        update(0,n,0,0,0,n);
        while (m--)
        {
            scanf("%d",&op);
            if (op==1)
            {
                scanf("%d",&len);
                int pos=query(len,0,0,n);
                printf("%d\n",pos+1);
                if (pos!=-1)    update(pos,pos+len,1,0,0,n);
            }
            else
            {
                scanf("%d %d",&a,&len);
                a--;
                update(a,a+len,0,0,0,n);
            }
        }
    }



    return 0;
}
