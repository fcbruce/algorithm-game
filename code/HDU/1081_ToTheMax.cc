/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 02 Jun 2015 12:15:32 AM CST
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

int a[maxn][maxn];
int col[maxn][maxn];
int v[maxn];

int max_sub(int a[],int l,int r)
{
  int sum,res;
  sum=res=a[l];
  for (int i=l+1;i<r;i++)
  {
    sum=max(sum+a[i],a[i]);
    res=max(res,sum);
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",a[i]+j);
    for (int i=1;i<=n;i++)
    {
      col[0][i]=0;
      for (int j=1;j<=n;j++) col[j][i]=col[j-1][i]+a[i][j];
    }
    int res=-INF;
    for (int i=1;i<=n;i++) for (int j=0;j<i;j++) 
    {
      for (int k=1;k<=n;k++) v[k]=col[i][k]-col[j][k];
      res=max(res,max_sub(v,1,n+1));
    }
    printf("%d\n",res);
  }



  return 0;
}
