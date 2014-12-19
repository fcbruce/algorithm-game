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
#define mm

using namespace std;

int dp[10001][40];
itn a[40];
itn s,l;

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d",&s,&l);

    for (int i=1;i<=l;i++)
    {
        int k=1,t=i;
        while (!(t&1))
        {
            k++;
            t>>=1;
        }
        a[k]++;

    }

    memset(dp,0,sizeof dp);
    dp[0][0]=1;

    for (int i=1;i<30;i++)
    {
        itn k=1<<(i-1);
        itn kk=1;

        while (kk<=a[i])
        {
            for (itn j=s;j>=k*kk;j--)
            {
                dp[j][0]|=dp[j-kk*k][0];
                dp[j][i]+=kk;
                a[i]-=kk;
                kk<<=1;
            }
        }

        if (a[i])
        {
            for (itn j=s;j>=k*a[i];j--)
            {
                dp[j][0]|=dp[j-a[i]*k][0];
                dp[j][i]+=a[i];
            }
        }
    }

    if (dp[s][0]==0)
    {
        puts("-1");
    }
    else
    {
        vector<int> v;
        for (int i=1;i<40;i++)
        {
            int k=1<<(i-1);
            for (int j=0;j<dp[s][i];j++)
            {
                v.push_back(1<<(i-1+j)|k);
            }

        }
        printf("%d\n",v.size());
        for (itn i=0;i<v.size();i++)
            printf("%d ",v[i]);
    }

    return 0;
}
