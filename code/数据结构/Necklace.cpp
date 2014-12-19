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
#define maxm 200007
#define maxn 50007

using namespace std;

int fir[1000007],_left[maxn];
LL _sum[maxn<<2];
int a[maxn];

struct _query
{
    int a,b,id;
    bool operator < (const _query &q)const
    {
        return b<q.b;
    }
}q[maxm];

LL ans[maxm];

void update(int p,int v,int k,int l,int r)
{
    if (r-l==1) _sum[k]=v;
    else
    {
        int m=l+r>>1;
        if (p<m)    update(p,v,k*2+1,l,m);  else    update(p,v,k*2+2,m,r);
        _sum[k]=_sum[k*2+1]+_sum[k*2+2];
    }
}

long long query(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;
    if (a<=l && r<=b)   return _sum[k];
    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,T_T;
    scanf("%d",&T_T);
    while (T_T--)
    {
        memset(_sum,0,sizeof _sum);
        scanf("%d",&n);
        memset(fir,-1,sizeof fir);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            _left[i]=fir[a[i]];
            fir[a[i]]=i;
        }

        scanf("%d",&m);

        for (int i=0;i<m;i++)
        {
            scanf("%d %d",&q[i].a,&q[i].b);
            q[i].id=i;
        }

        sort(q,q+m);

        for (int i=0,j=0;i<m;i++)
        {
            while (j<n && j<q[i].b)
            {
                if (_left[j]!=-1)
                    update(_left[j],0,0,0,n);

                update(j,a[j],0,0,n);
                j++;
            }

            ans[q[i].id]=query(q[i].a-1,q[i].b,0,0,n);
        }

        for (int i=0;i<m;i++)   printf("%I64d\n",ans[i]);
    }


    return 0;
}
