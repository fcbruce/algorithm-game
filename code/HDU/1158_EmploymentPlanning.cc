/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 02 Jun 2015 10:02:34 PM CST
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

#define maxm 107
#define maxn 17

using namespace std;

int a[maxn],dp[maxn][maxm];
int h,s,f;

inline int calc(int i,int j,int k)
{
  int res=0;
  if (j<k)
    res+=(k-j)*f;
  else
    res+=(j-k)*h;

  res+=j*s;
  
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n),n!=0)
  {
    scanf("%d%d%d",&h,&s,&f);
    
    a[0]=0;
    for (int i=1;i<=n;i++) scanf("%d",a+i);

    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
      for (int j=a[i];j<maxm;j++) for (int k=a[i-1];k<maxm;k++) dp[i][j]=min(dp[i][j],dp[i-1][k]+calc(i,j,k));

    int res=INF;
    for (int i=a[n];i<maxm;i++) res=min(res,dp[n][i]);
    printf("%d\n",res);
  }




  return 0;
}
