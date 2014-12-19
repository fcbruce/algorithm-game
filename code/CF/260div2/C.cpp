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
#define maxn 100000

using namespace std;

long long  dp[123456];
int a[123456];
int __hash[123456];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d",&n);

    memset(__hash,0,sizeof __hash);
    memset(dp,0,sizeof dp);
    itn x;

    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        __hash[x]++;
    }

    dp[1]=__hash[1];
    long long MAX=0;

    for (int i=2;i<maxn+1;i++)
    {
        dp[i]=MAX+(LL)__hash[i]*i;
        MAX=max(dp[i-1],MAX);
    }

    cout<<max(dp[maxn],dp[maxn-1])<<endl;

    return 0;
}
