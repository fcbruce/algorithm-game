/*
 *
 * Author : fcbruce
 *
 * Time : Thu 02 Oct 2014 06:45:31 PM CST
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

int sum[maxn<<2],lsum[maxn<<2],rsum[maxn<<2],msum[maxn<<2];

inline void pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;

  sum[k]=sum[lc]+sum[rc];

  lsum[k]=max(lsum[lc],lsum[rc]+sum[lc]);
  rsum[k]=max(rsum[rc],rsum[lc]+sum[rc]);
  msum[k]=max(rsum[lc]+lsum[rc],max(msum[lc],msum[rc]));
}

void build(int k,int l,int r)
{
  if (r-l==1)
  {
    scanf("%d",sum+k);
    lsum[k]=rsum[k]=msum[k]=sum[k];
    return ;
  }

  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);

  pushup(k);
}

void update(int p,int v,int k,int l,int r)
{
  if (r-l==1)
  {
    sum[k]=lsum[k]=rsum[k]=msum[k]=v;
    return ;
  }

  int m=l+r>>1;

  if (p<m)
    update(p,v,k*2+1,l,m);
  else
    update(p,v,k*2+2,m,r);

  pushup(k);
}

int query_l(int a,int b,int k,int l,int r)
{
  if (r<=b) return lsum[k];

  int lc=k*2+1,rc=k*2+2,m=l+r>>1;

  if (b<=m) return query_l(a,b,lc,l,m);

  return max(lsum[lc],max(sum[lc],sum[lc]+query_l(a,b,rc,m,r)));

}

int query_r(int a,int b,int k,int l,int r)
{
  if (a<=l) return rsum[k];

  int lc=k*2+1,rc=k*2+2,m=l+r>>1;

  if (m<=a) return query_r(a,b,rc,m,r);

  return max(rsum[rc],max(sum[rc],sum[rc]+query_r(a,b,lc,l,m)));
}

int query(int a,int b,int k,int l,int r)
{
  if (a<=l && r<=b) return msum[k];

  int lc=k*2+1,rc=k*2+2,m=l+r>>1;

  if (b<=m) return query(a,b,lc,l,m);
  if (m<=a) return query(a,b,rc,m,r);

  return max(query_r(a,b,lc,l,m)+query_l(a,b,rc,m,r),max(query(a,b,lc,l,m),query(a,b,rc,m,r)));
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,op,a,b;

  scanf("%d",&n);

  build(0,0,n);

  scanf("%d",&m);

  while (m--)
  {
    scanf("%d%d%d",&op,&a,&b);
    a--;

    if (op==0)
      update(a,b,0,0,n);
    else
      printf("%d\n",query(a,b,0,0,n));
  }


  return 0;
}
