/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 28 Dec 2014 08:38:44 PM CST
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

long long sum[44444];

inline void init()
{
  sum[0]=0;
  sum[1]=1;
  for (int i=2,j=3;i<40000;i++,j+=2)
    sum[i]=sum[i-1]+j;
}

inline int d(int l,int i)
{
  return i-sum[l-1]-1>>1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int s,t;

  init();

  while (scanf("%d%d",&s,&t)==2)
  {
    if (s<t) swap(s,t);

    int ls=lower_bound(sum,sum+40000,(long long)s)-sum;
    int lt=lower_bound(sum,sum+40000,(long long)t)-sum;

    if (ls==lt)
    {
      printf("%d\n",abs(s-t));
      continue;
    }

    int dt=d(lt,t),ct=2*lt-1,cs=2*ls-1;

    int MIN=INF;
    for (int i=s,go=0;ls>=lt;go++)
    {
      if (ls==lt)
      {
        MIN=min(MIN,go+abs(i-t));
        break;
      }
      int di=d(ls,i);
      if (di==dt || (sum[lt]-t)/2==(sum[ls]-i)/2)
      {
        int d=(ls-lt)<<1;
        d++;
        if ((t-sum[lt-1])&1) d--;
        if (!((i-sum[ls-1])&1)) d--;
        MIN=min(MIN,go+d); 
      }
      if (i-sum[ls-1]==1) break;
      if ((i-sum[ls-1])&1) i--;
      else
      {
        i-=(ls-1)*2;
        ls--;
      }
    }

    printf("%d\n",MIN);

  }

  return 0;
}
