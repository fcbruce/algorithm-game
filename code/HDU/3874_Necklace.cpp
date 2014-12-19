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
#define mm 50007

using namespace std;

int _hash[1000007],a[mm],pos[mm];
LL _sum[mm<<2],ans[mm<<2];
struct _query
{
    int l,r,id;
    bool operator < (const _query &q)const
    {
        return r<q.r;
    }
}q[mm<<2];

void update(int p,itn v,int k,int l,int r)
{
    //if (p<l ||p>=r) return ;

    if (r-l==1)
    {
        _sum[k]=v;
        return ;
    }

    int m=l+r>>1;

    if (p<m)    update(p,v,k*2+1,l,m);  else    update(p,v,k*2+2,m,r);

    _sum[k]=_sum[k*2+1]+_sum[k*2+2];
}

LL query(itn a,int b,int k,itn l,itn r)
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
    #endif // ONLINE_JUDGE

    int T_T,n,m;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d",&n);
        for (itn i=0;i<n;i++)   scanf("%d",a+i);
        scanf("%d",&m);
        for (itn i=0;i<m;i++)   scanf("%d%d",&q[i].l,&q[i].r),q[i].l--,q[i].id=i;

        sort(q,q+m);

        memset(_hash,-1,sizeof _hash);
        //memset(pos,-1,sizeof pos);
        for (int i=0;i<n;i++)
        {
            pos[i]=_hash[a[i]];
            _hash[a[i]]=i;
        }

        memset(_sum,0,sizeof _sum);

        for (int i=0,j=0;i<m;i++)
        {
            while (j<q[i].r)
            {
                if (pos[j]!=-1)
                    update(pos[j],0,0,0,n);
                update(j,a[j],0,0,n);
                j++;

            }


            ans[q[i].id]=query(q[i].l,q[i].r,0,0,n);
        }

        for (itn i=0;i<m;i++)   printf("%I64d\n",ans[i]);
    }

    return 0;
}
