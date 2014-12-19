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
#define maxn 5000

using namespace std;

int s[maxn<<2];

void update(itn p,int k,int l,int r)
{
    s[k]++;
    if (r-l==1)
        return ;
    else
    {
        int m=l+r>>1;
        if (p<m)    update(p,k*2+1,l,l+r>>1);   else    update(p,k*2+2,l+r>>1,r);
    }
}

int query(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;
    if (a<=l && r<=b)   return s[k];
    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;
    int a[maxn];

    while (~scanf("%d",&n))
    {
        memset(s,0,sizeof s);
        for (int i=0;i<n;i++)
            scanf("%d",a+i);

        int total=0;
        for (int i=0;i<n;i++)
        {
            total+=query(a[i]+1,n,0,0,n);
            update(a[i],0,0,n);
        }

        int MIN=total;
        for (int i=0;i<n;i++)
        {
            total=total-a[i]+n-a[i]-1;
            MIN=min(MIN,total);
        }
        printf("%d\n",MIN);
    }


    return 0;
}
