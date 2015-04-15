/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 08:06:15 PM CST
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
#define maxn 2000007

using namespace std;

int a[maxn];
int sum[maxn];

int q[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n),n!=0)
  {
    for (int i=1;i<=n;i++)
    {
      scanf("%d",a+i);
      a[i+n]=a[i];
    }

    sum[0]=0;
    n<<=1;

    for (int i=1;i<=n;i++)
      sum[i]=sum[i-1]+a[i];


    int f=0,r=-1;

    for (int i=n;i>n/2;i--)
    {
      while (f<=r && sum[q[f]]>=sum[i]) f++;
      q[++r]=i;
    }

    int cnt=0;
    for (int i=n/2;i;i--)
    {
      while (f<=r && (sum[q[f]]>=sum[i] || q[f]-n/2>i)) f++;
      if (r<f) cnt++;
      q[++r]=i;
    }

    printf("%d\n",cnt);
  }



  return 0;
}
