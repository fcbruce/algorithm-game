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
#define mm 100010

using namespace std;

LL sum[mm];
int a[mm],l[mm],r[mm];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE


    int n;
    //while (~scanf("%d",&n))
    {
        scanf("%d",&n);
        a[0]=a[n+1]=0;
        sum[0]=0;
        for (itn i=1;i<=n;i++)  {scanf("%d",a+i);l[i]=r[i]=i;sum[i]=sum[i-1]+a[i];}

        l[0]=r[0]=0;
        l[n+1]=r[n+1]=n+1;

        for (int i=1;i<=n;i++)
            while (l[i]-1>0 && a[i]<=a[l[i]-1])
                l[i]=l[l[i]-1];

        for (int i=n;i;i--)
            while (r[i]+1<n+1 && a[i]<=a[r[i]+1])
                r[i]=r[r[i]+1];

        LL ans=-1,ll,rr;

        for (int i=1;i<=n;i++)
        {
            //ans=max(ans,(sum[r[i]]-sum[l[i]-1])*a[i]);
//            printf("%d %d %d\n",l[i],r[i],(sum[r[i]]-sum[l[i]-1])*a[i]);
            LL k=(sum[r[i]]-sum[l[i]-1])*a[i];
            if (ans<k)
            {
                ans=k;
                ll=l[i];
                rr=r[i];
            }
        }

        cout<<ans<<endl;
        cout<<ll<<' '<<rr<<endl;
    }

    return 0;
}
