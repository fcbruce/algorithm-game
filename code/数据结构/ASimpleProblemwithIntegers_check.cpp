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

LL add[mm<<2];
LL sum[mm<<2];

void pushup(int k,int l,int r)
{
	sum[k]=0;
	if (r-l>1)	
	{
		sum[k]=sum[k*2+1]+sum[k*2+2];
	}
	sum[k]+=add[k]*(r-l);
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a) return;

    if (a<=l && r<=b)   add[k]+=v;
    else
    {
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
    
    pushup(k,l,r);
}

LL query(int a,int b,int k,itn l,itn r,LL _add)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)    return _add*(r-l)+sum[k];

    LL res=0;
    res+=query(a,b,k*2+1,l,l+r>>1,_add+add[k]);
    res+=query(a,b,k*2+2,l+r>>1,r,_add+add[k]);

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
        char op[5];
        while (q--)
        {
            scanf("%s",op);
            if (op[0]=='C')
            {
                scanf("%d %d %d",&a,&b,&v);
                a--;
                update(a,b,v,0,0,n);
            }
            else
            {
                scanf("%d %d",&a,&b);
                a--;
                printf ("%lld\n",query(a,b,0,0,n,0));
            }
        }
    }


    return 0;
}
