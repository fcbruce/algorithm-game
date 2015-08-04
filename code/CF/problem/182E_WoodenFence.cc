/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 04 Aug 2015 07:15:00 PM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 3007

using namespace std;

const long long mod = 1000000007ll;

long long dp[107][maxn][2];
int a[maxn],b[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,l;
  scanf("%d%d",&n,&l);

  memset(dp,0,sizeof dp);

  for (int i=0;i<n;i++)
  {
    scanf("%d%d",a+i,b+i);
    dp[i][a[i]][0]=1;
    if (a[i]!=b[i]) dp[i][b[i]][1]=1;
  }

  for (int j=1;j<=l;j++)
  {
    for (int i=0;i<n;i++)
    {
      if (a[i]<j)
      {
        for (int k=0;k<n;k++) if (i!=k)
        {
          if (a[i]==b[k])
          {
            dp[i][j][0]+=dp[k][j-a[i]][0];
            dp[i][j][0]%=mod;
          }
          if (a[i]==a[k])
          {
            dp[i][j][0]+=dp[k][j-a[i]][1];
            dp[i][j][0]%=mod;
          }
        }
      }
      if (a[i]!=b[i] && b[i]<j)
      {
        for (int k=0;k<n;k++) if (i!=k)
        {
          if (b[i]==b[k])
          {
            dp[i][j][1]+=dp[k][j-b[i]][0];
            dp[i][j][1]%=mod;
          }
          if (b[i]==a[k])
          {
            dp[i][j][1]+=dp[k][j-b[i]][1];
            dp[i][j][1]%=mod;
          }
        }
      }
    }
  }

  long long res=0;
  for (int i=0;i<n;i++)
  {
    res+=(dp[i][l][0]+dp[i][l][1])%mod;
    res%=mod;
  }
  printf(lld "\n",res);


  return 0;
}
