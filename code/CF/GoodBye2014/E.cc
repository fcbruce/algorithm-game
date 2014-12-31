/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 31 Dec 2014 12:46:09 AM CST
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
#define maxn 400007

using namespace std;

long long lenv[maxn<<2],setv[maxn<<2],X[maxn<<2];
long long ans[maxn];

inline void pushup(int k)
{
  lenv[k]=lenv[k*2+1]+lenv[k*2+2];
}

void build(int k,int l,int r)
{
  setv[k]=1;
  if (r-l==1)
  {
    lenv[k]=X[r]-X[l];
    setv[k]=1;
    return ;
  }

  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);
  pushup(k);
}

void pushdown(int k)
{
  if (setv[k]==0)
  {
    setv[k*2+1]=setv[k*2+2]=0;
    lenv[k*2+1]=lenv[k*2+2]=0;
  }
}

void update(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    setv[k]=0;
    lenv[k]=0;
    return ;
  }
  
  pushdown(k);

  update(a,b,k*2+1,l,l+r>>1);
  update(a,b,k*2+2,l+r>>1,r);
  pushup(k);
}

long long query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0ll;
  if (a<=l && r<=b) return lenv[k];

  pushdown(k);

  return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

struct qqq
{
  int x,y,id;
  bool operator < (const qqq &_)const
  {
    return x>_.x;
  }
}q[maxn];

long long p[maxn],h[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  
  scanf("%d",&n);
  for (int i=1;i<=n;i++) scanf(lld lld,p+i,h+i);

  scanf("%d",&m);

  for (int i=0;i<m;i++){
    scanf("%d%d",&q[i].x,&q[i].y);
    q[i].id=i;
  }

  sort(q,q+m);

  int xn=0;
  for (int i=1;i<=n;i++)
  {
    X[xn++]=p[i];
    X[xn++]=p[i]+h[i];
  }

  sort(X,X+xn);
  xn=unique(X,X+xn)-X;

  build(0,0,xn);

  for (int i=0,j=n;i<m;i++)
  {
    while (j>=q[i].x)
    {
      int a=lower_bound(X,X+xn,p[j])-X;
      int b=lower_bound(X,X+xn,p[j]+h[j])-X;
      update(a,b,0,0,xn);
      j--;
    }
    int l=p[q[i].x],r=p[q[i].y];
    int a=lower_bound(X,X+xn,l)-X;
    int b=lower_bound(X,X+xn,r)-X;
    ans[q[i].id]=query(a,b,0,0,xn);

  }

  for (int i=0;i<m;i++) printf(lld "\n",ans[i]);


  return 0;
}
