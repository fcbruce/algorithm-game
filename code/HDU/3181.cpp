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
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm 1000001

using namespace std;

int dp[mm];

int dfs(int x)
{
    if (x<mm) return dp[x];

    int r=x>>1;

    if (x&1)
        return dfs(r)+dfs(x-r)+1;

    return dfs(r)<<1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for (int i=2;i<mm;i++)
    {
        int r=i>>1;
        if (i&1)
        {
            dp[i]=dp[r]+dp[i-r]+1;
        }
        else
        {
            dp[i]=dp[r]<<1;
        }
    }

    int tt,n;
    scanf("%d",&tt);

    while (tt--)
    {
        scanf("%d",&n);
        printf("%d\n",dfs(n));
    }


	return 0;
}
