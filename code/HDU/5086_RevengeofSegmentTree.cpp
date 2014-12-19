/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 02 Nov 2014 10:51:17 AM CST
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

const long long mod = 1000000007ll;

inline long long multiply(long long a,long long b)
{
  return a*b%mod;
}

inline long long add(long long a,long long b)
{
  return (a+b)%mod;
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
    int n;
    scanf("%d",&n);

    long long sum=0ll,x;
    for (int i=1;i<=n;i++)
    {
      scanf(lld,&x);
      sum=add(sum,multiply(x,multiply(i,n+1-i)));
    }
    printf(lld"\n",sum);
  }



  return 0;
}
