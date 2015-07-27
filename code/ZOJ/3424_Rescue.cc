/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 06:47:07 PM CST
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
#define maxn 50007

using namespace std;

int a[maxn];
int hit[maxn];

inline long long ok(long long p,int k,int n)
{
  int res=0,cnt=0;
  long long less2=0,less=0;
  for (int i=n-1,j=i;i>=0;i--)
  {
    while (sqr((long long)(j-i))>=p)
    {
      less2-=hit[j]*(sqr((long long)(j-i-1)));
      less-=hit[j]*(j-i-1);
      cnt-=hit[j];
      j--;
    }
    less2+=less*2+cnt;
    less+=cnt;
    if (a[i]<(cnt*p-less2)) hit[i]=0;
    else hit[i]=(a[i]-cnt*p+less2)/p+1;
    cnt+=hit[i];
    res+=hit[i];
    if (res>k) return false;
  }
  return res<=k;
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
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",a+i);
    long long l=1,r=1ll<<60,res=r;
    while (l<=r)
    {
      long long mid=l+r>>1;
      if (ok(mid,k,n))
      {
        res=mid;
        r=mid-1;
      }
      else l=mid+1;
    }
    printf("%lld\n",res);
  }



  return 0;
}
