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
#define mm 100000

using namespace std;

LL _a[mm<<2];
LL _b[mm<<2];

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a) return;

    if (a<=l && r<=b)   _a[k]+=v;
    else
    {
        _b[k]+=(min(r,b)-max(a,l))*v;
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
}

LL query(int a,int b,int k,itn l,itn r)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)    return _a[k]*(r-l)+_b[k];

    LL res=0;
    res=_a[k]*(min(r,b)-max(l,a));
    res+=query(a,b,k*2+1,l,l+r>>1);
    res+=query(a,b,k*2+2,l+r>>1,r);

    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,q,a,b,v;
    while (~scanf("%d %d",&n,&q))
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&v);
            update(i,i+1,v,0,0,n);
        }
        char op;
        while (q--)
        {
            scanf("%1s",&op);
            if (op=='C')
            {
                scanf("%d %d %d",&a,&b,&v);
                a--;
                update(a,b,v,0,0,n);
            }
            else
            {
                scanf("%d %d",&a,&b);
                a--;
                printf ("%lld\n",query(a,b,0,0,n));
            }
        }
    }


    return 0;
}
