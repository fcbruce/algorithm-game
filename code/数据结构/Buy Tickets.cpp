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
#define maxn 200007

using namespace std;

itn pos[maxn],val[maxn];
int ans[maxn];
int rest[maxn<<2];

void build(int k,int l,int r)
{
    rest[k]=r-l;
    if (r-l==1) return ;
    build(k*2+1,l,l+r>>1);
    build(k*2+2,l+r>>1,r);
}

int query(int _rest,int k,int l,int r)
{
    rest[k]--;
    if (r-l==1) return l;
    if (_rest<rest[k*2+1])//左儿子区间内可放
    {
        return query(_rest,k*2+1,l,l+r>>1);
    }
    else//左儿子放不下，放在右儿子里
    {
        return query(_rest-rest[k*2+1],k*2+2,l+r>>1,r);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;
    while (~scanf("%d",&n))
    {
        for (itn i=0;i<n;i++)
        {
            scanf("%d %d",pos+i,val+i);
        }

        build(0,0,n);

        for (int i=n-1;i>=0;i--)
        {
            ans[query(pos[i],0,0,n)]=val[i];
        }

        for (int i=0;i<n;i++)
            printf(i?" %d":"%d",ans[i]);
        puts("");
    }

    return 0;
}
