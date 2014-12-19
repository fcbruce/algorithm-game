/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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
#define maxn 100100

using namespace std;

long long col[maxn<<2],sum[maxn<<2],diff[maxn<<2];

inline void
pushdown(int k,int l,int r)
{
  if (col[k]>0)
  {
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;
    
    sum[lc]+=diff[k]*(m-l);
    sum[rc]+=diff[k]*(r-m);
    
    diff[lc]+=diff[k];
    diff[rc]+=diff[k];
    
    col[lc]=col[rc]=col[k];
    
    col[k]=-1;
    diff[k]=0;
  }
}

inline void
pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;
  sum[k]=sum[lc]+sum[rc];
  if (col[lc]==col[rc]) col[k]=col[lc];
}

void
build(int k,int l,int r)
{
  if (r-l==1)
  {
    col[k]=l;
    return ;
  }
  
  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);
  
}

void
update(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    if (col[k]>0)
    {
      sum[k]+=abs(col[k]-v)*(r-l);
      diff[k]+=abs(col[k]-v);
      col[k]=v;
      return ;
    }
  }
  
  pushdown(k,l,r);
  
  update(a,b,v,k*2+1,l,l+r>>1);
  update(a,b,v,k*2+2,l+r>>1,r);
  
  pushup(k);
}

long long
query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return sum[k];
  
  pushdown(k,l,r);
  
  long long res=query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
  
  pushup(k);
  
  return res;
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n,m;
  
  scanf("%d%d",&n,&m);
  n++;
  
  memset(diff,0,sizeof diff);
  memset(sum,0,sizeof sum);
  memset(col,-1,sizeof col);
  
  build(0,1,n);
  
  int op,a,b,x;
  while (m--)
  {
    scanf("%d",&op);
    
    if (op==1)
    {
      scanf("%d%d%d",&a,&b,&x);
      b++;
      update(a,b,x,0,1,n);
    }
    else
    {
      scanf("%d%d",&a,&b);
      b++;
      printf(lld "\n",query(a,b,0,1,n));
    }
  }
  
  
  return 0;
}



