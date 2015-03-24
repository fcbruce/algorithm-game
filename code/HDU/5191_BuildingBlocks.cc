/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 21 Mar 2015 07:09:55 PM CST
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
#define maxn 150007

using namespace std;

long long a[maxn];
long long add[maxn];
long long cut[maxn];
long long n,w,h;
long long tot=0;

long long solve()
{
  if (w*h>tot) return -1;

  add[0]=cut[0]=0;
  long long  res=INF;

  for (int i=1;i<=w;i++)
  {
    if (a[i]>h) {
      cut[i]=cut[i-1]+a[i]-h;
      add[i]=add[i-1];
    }
    else {
      add[i]=add[i-1]+h-a[i];
      cut[i]=cut[i-1];
    }
  }

  res=max(add[w],cut[w]);

  for (int i=w+1;i<=w+w+n;i++)
  {
    if (a[i]>h) {
      cut[i]=cut[i-1]+a[i]-h;
      add[i]=add[i-1];
    }
    else {
      add[i]=add[i-1]+h-a[i];
      cut[i]=cut[i-1];
    }

    res=min(res,max(add[i]-add[i-w],cut[i]-cut[i-w]));
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  
  while (scanf(lld lld lld,&n,&w,&h)==3)
  {
    tot=0;
    memset(a,0,sizeof a);
    for (int i=w+1;i<=w+n;i++) 
    {
      scanf(lld,a+i);
      tot+=a[i];
    }

    printf(lld"\n",solve());
  }



  return 0;
}
