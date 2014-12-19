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
#define mm 100010<<2

using namespace std;

itn setv[mm],sumv[mm];
int _sum;

void maintain(int k,int l,int r)
{
    if (setv[k]>0)
    {
        sumv[k]=setv[k]*(r-l);
    }
    else
    {
        sumv[k]=sumv[k*2+1]+sumv[k*2+2];
    }
}

void pushdown(itn k)
{
    if (setv[k]>0)
    {
        setv[k*2+1]=setv[k*2+2]=setv[k];
        setv[k]=-1;
    }
}

void update(int a,int b,int v,int  k,int l,int r)
{
    if (a<=l && r<=b)
    {
        setv[k]=v;
    }
    else
    {
        pushdown(k);
        int m=l+r>>1;
        if (a<m)   update(a,b,v,k*2+1,l,m);    else    maintain(k*2+1,l,m);
        if (b>m)   update(a,b,v,k*2+2,m,r);    else    maintain(k*2+2,m,r);
    }
    maintain(k,l,r);
}

void query(int a,int b,int k,int l,int r)
{
    if (setv[k]>0)
    {
        _sum+=setv[k]*(min(r,b)-max(l,a));
    }
    else
    {
        if (a<=l && r<=b)
        {
            _sum+=sumv[k];
        }
        else
        {
            int m=l+r>>1;
            if (a<m)    query(a,b,k*2+1,l,m);
            if (b>=m)   query(a,b,k*2+2,m,r);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,q,a,b,v;
    scanf("%d",&T_T);
    int t=1;
    while (T_T--)
    {
        scanf("%d %d",&n,&q);
        memset(setv,-1,sizeof setv);
        update(0,n,1,0,0,n);
        while (q--)
        {
            scanf("%d %d %d",&a,&b,&v);
            a--;
            update(a,b,v,0,0,n);
        }

        _sum=0;
        query(0,n,0,0,n);
        printf("Case %d: The total value of the hook is %d.\n",t++,_sum);
    }

    return 0;
}
