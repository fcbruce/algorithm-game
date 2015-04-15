/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Apr 2015 08:53:45 PM CST
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

long long calc(long long x)
{
  long long res=0;
  if ((x+1>>1)&1) res|=1;
  for (int i=62;i>0;i--)
  {
    if (x>=(1ll<<i))
    {
      long long cnt=x-(1ll<<i) +1;
      if (cnt&1) res|=1ll<<i;
      x-=1ll<<i;
    }
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  long long res=0;

  while (n--)
  {
    long long x,m;
    scanf(lld lld,&x,&m);
    res^=calc(x-1)^calc(x+m-1);
  }

  if (res==0ll) puts("bolik");
  else puts("tolik");

  return 0;
}
