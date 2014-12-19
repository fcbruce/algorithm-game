/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 25 Oct 2014 06:46:26 PM CST
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
#define maxn 200007

using namespace std;

int beans[maxn];
int row[maxn];
int n,m;
int dp[2][maxn];

int solve(int a[],int n)
{
  dp[0][0]=0;
  dp[1][0]=a[0];

  for (int i=1;i<n;i++)
  {
    dp[0][i]=max(dp[0][i-1],dp[1][i-1]);
    dp[1][i]=dp[0][i-1]+a[i];
  }

  return max(dp[0][n-1],dp[1][n-1]);
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&m)==2)
  {
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        scanf("%d",&beans[i*m+j]);

    for (int i=0;i<n;i++)
      row[i]=solve(beans+i*m,m);

    printf("%d\n",solve(row,n));
  }


  return 0;
}
