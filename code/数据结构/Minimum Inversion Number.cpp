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
#define mm 5007

using namespace std;

int a[mm];
itn _minv[mm<<2],_maxv[mm<<2];
int _sumv[mm<<2];

void update(itn p,int k,int l,int r)
{
    if (r-l==1)
    {
        _sumv[k]=1;
        return ;
    }

    int m=l+r>>1;
    if (p<m)    update(p,k*2+1,l,m);  else    update(p,k*2+2,m,r);
    _sumv[k]=_sumv[k*2+1]+_sumv[k*2+2];
}

int query(itn a,int b,int k,int l,int r)
{
    if (b<=r || r<=a)   return 0;

    if (a<=l && r<=b)   return _sumv[k];

    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;

    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;i++)
            scanf("%d",a+i);

        memset(_sumv,0,sizeof _sumv);

        int s=0;
        for (int i=0;i<n;i++)
        {
            s+=query(a[i]+1,n+1,0,0,n);
            update(a[i],0,0,n);
        }

        itn ans=s;
        int t=a[0];
        for (int i=1;i<n;i++)
        {
            s=s+n-1-(t<<1);
            t=a[i];
            ans=min(ans,s);
        }

        printf("%d\n",ans);
    }


    return 0;
}
