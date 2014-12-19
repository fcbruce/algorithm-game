/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 19 Nov 2014 03:43:17 PM CST
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

long long maxv[maxn<<2],minv[maxn<<2],setv[maxn<<2];

inline void pushdown(int k)
{
  if (setv[k]!=0ll)
  {
    int lc=k*2+1,rc=k*2+2;
    setv[lc]=setv[rc]=maxv[lc]=maxv[rc]=minv[lc]=minv[rc]=setv[k];
    setv[k]=0;
  }
}

inline void pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;
  maxv[k]=max(maxv[lc],maxv[rc]);
  minv[k]=min(minv[lc],minv[rc]);
}

void update(int a,int b,LL h,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (minv[k]>h) return ;
  if (a<=l && r<=b)
  {
    if (maxv[k]<=h)
    {
      setv[k]=minv[k]=maxv[k]=h;
      return ;
    }
  }

  pushdown(k);
  update(a,b,h,k*2+1,l,l+r>>1);
  update(a,b,h,k*2+2,l+r>>1,r);
  pushup(k);
}

int query(int a,int b,LL h,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (minv[k]>h) return 0;
  if (a<=l && r<=b)
    if (maxv[k]<=h) return r-l;

  pushdown(k);
  return query(a,b,h,k*2+1,l,l+r>>1)+query(a,b,h,k*2+2,l+r>>1,r);
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

    memset(maxv,0,sizeof maxv);
    memset(minv,0,sizeof minv);
    memset(setv,0,sizeof setv);

    int total=0;
    int l,r;
    long long h;

    while (n--)
    {
      scanf("%d%d"lld,&l,&r,&h);
      l--;r--;
      total+=query(l,r,h,0,0,maxn);
      update(l,r,h,0,0,maxn);
    }

    printf("%d\n",total);
  }


  return 0;
}
