/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 30 Oct 2014 11:03:13 AM CST
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
#define maxn 107

using namespace std;

int G[maxn][maxn],dp[maxn][maxn];

inline int add(int a,int b)
{
  return (a+b)%10000;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        scanf("%d",&G[i][j]);

    memset(dp,0,sizeof dp);
    dp[0][0]=1;

    for (int i=0;i<n;i++)
    {
      for (int j=0;j<m;j++)
      {
        for (int k=0;k<=G[i][j];k++)
        {
          for (int l=0;l<=G[i][j]-k;l++)
          {
            if ((k||l) && i+k<n && j+l<m)
              dp[i+k][j+l]=add(dp[i+k][j+l],dp[i][j]);
          }
        }
      }
    }

    printf("%d\n",dp[n-1][m-1]);
  }



  return 0;
}
