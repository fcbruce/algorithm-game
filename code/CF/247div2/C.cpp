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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm 1000000007

using namespace std;

int dp[101][101];
int n,k,d;

int f(int x,int y)
{
    if (dp[x][y]!=-1)   return dp[x][y];

    if (x<y)    return dp[x][y]=0;

    if (y==0)   return dp[x][y]=0;

    int s=0;

    for (int i=1;i<=y;i++)
    {
        if (x>=i)
        {
            s+=f(x-i,y);
            s=s%mm;
        }
    }

    return dp[x][y]=s;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d",&n,&k,&d);

    memset(dp,0,sizeof(dp));

    dp[0][0]=0;
    for (int i=1;i<=k;i++)
        dp[i][i]=1;

    //f(n,k);

    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=k;j++)
        {
            for (int s=1;s<=j && s<=i;s++)
            {

                dp[i][j]+=dp[i-s][j];
                dp[i][j]%=mm;
            }
            for (int s=1;s<j;s++)
            {
                if (i-j>0)
                {
                    dp[i][j]+=dp[i-j][s];
                    dp[i][j]%=mm;
                }

            }

        }
    }

    int ans=0;

    for (int i=d;i<=k;i++)
    {
        if (dp[n][i]!=-1)
        {
            ans+=dp[n][i];
            ans%=mm;
        }
    }

    printf("%d\n",ans);



    return 0;
}
