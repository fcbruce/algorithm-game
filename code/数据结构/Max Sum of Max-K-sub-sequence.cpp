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
#define mm 100007<<1

using namespace std;

int dp[mm];
int __start,_end;
int q[mm],a[mm],f,r;
int sum[mm];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,k;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d%d",&n,&k);

        sum[0]=0;
        for (itn i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i+n]=a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for (int i=1;i<=n;i++)
            sum[i+n]=sum[i-1+n]+a[i];

        itn ans=-INF;
        f=0;r=-1;
        q[++r]=0;
        for (int i=1;i<=n<<1;i++)
        {
            while (f<=r && q[f]<i-k)  f++;

            if (f<=r)
            {
                dp[i]=sum[i]-sum[q[f]];
                if (dp[i]>ans)
                {
                    ans=dp[i];
                    __start=q[f]+1;
                    _end=i;
                }
            }

            while (f<=r && sum[q[r]]>sum[i]) r--;
            q[++r]=i;
        }

        printf("%d %d %d\n",ans,__start>n?__start-n:__start,_end>n?_end-n:_end);

    }

    return 0;
}
