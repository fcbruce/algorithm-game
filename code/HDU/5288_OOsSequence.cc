/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 24 Jul 2015 09:47:18 AM CST
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
#define maxn 100007

using namespace std;

const long long mod = 1000000007ll;

int l[maxn],r[maxn];
int a[maxn];
int pos[maxn];

inline long long add(long long lhs,long long rhs)
{
  return (lhs + rhs) % mod;
}

inline long long multi(int lhs,int rhs)
{
  return ((long long )lhs * rhs) % mod;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n)==1)
  {
    for (int i=0;i<n;i++) scanf("%d",a+i);
    fill(l,l+n,-1);
    fill(r,r+n,n);
    memset(pos,-1,sizeof pos);
    for (int i=0;i<n;i++)
    {
      for (int j=1;sqr(j)<=a[i];j++) if (a[i]%j==0) l[i]=max(l[i],max(pos[j],pos[a[i]/j]));
      pos[a[i]]=i;
    }
    memset(pos,0x3f,sizeof pos);
    for (int i=n-1;i>=0;i--)
    {
      for (int j=1;sqr(j)<=a[i];j++) if (a[i]%j==0) r[i]=min(r[i],min(pos[j],pos[a[i]/j]));
      pos[a[i]]=i;
    }
    long long res =0ll;
    for (int i=0;i<n;i++) res = add(res,multi(i-l[i],r[i]-i));
    printf(lld "\n",res);
  }



  return 0;
}
