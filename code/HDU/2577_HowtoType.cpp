/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 22 Oct 2014 09:14:56 AM CST
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
#define maxn 

using namespace std;

int dp[2][111];
char str[111];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%s",str+1);
    int l=strlen(str+1);
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    dp[1][0]=1;

    for (int i=1;i<=l;i++)
    {
      if (isupper(str[i]))
      {
        dp[1][i]=min(dp[1][i-1]+1,dp[0][i-1]+2);
        dp[0][i]=min(dp[0][i-1]+2,dp[1][i-1]+2);
      }
      else
      {
        dp[0][i]=min(dp[0][i-1]+1,dp[1][i-1]+2);
        dp[1][i]=min(dp[1][i-1]+2,dp[0][i-1]+2);
      }
    }

    printf("%d\n",min(dp[0][l],dp[1][l]+1));


  }



  return 0;
}
