/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Jul 2015 01:50:00 PM CST
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

int minv[maxn<<2],setv[maxn<<2];

struct rectangle
{
  int x1,y1,x2,y2;
  void read()
  {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x2<x1) swap(x1,x2);
    if (y2<y1) swap(y1,y2);
  }
  void rotate()
  {
    swap(x1,y1);
    swap(x2,y2);
  }
}rec[maxn];

struct segment
{
  int x1,x2,y,v;
  bool operator < (const segment &rhs) const
  {
    return y==rhs.y?v<rhs.v:y<rhs.y;
  }
}seg[maxn<<1];

int X[maxn];

inline void pushdown(int k)
{
  if (setv[k]!=-1)
  {
    int lc=k*2+1,rc=k*2+2;
    minv[lc]=minv[rc]=setv[k];
    setv[lc]=setv[rc]=setv[k];
    setv[k]=-1;
  }
}

inline void pushup(int k)
{
  minv[k]=min(minv[k*2+1],minv[k*2+2]);
}

void update(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    setv[k]=minv[k]=v;
    return ;
  }
  pushdown(k);
  update(a,b,v,k*2+1,l,l+r>>1);
  update(a,b,v,k*2+2,l+r>>1,r);
  pushup(k);
}

long long query(int a,int b,int v,int M,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (v-minv[k]<=M) return 0;
  if (a<=l && r<=b) if (setv[k]!=-1) return (long long)(v-setv[k]-M)*(X[r]-X[l]);
  pushdown(k);
  return query(a,b,v,M,k*2+1,l,l+r>>1)+query(a,b,v,M,k*2+2,l+r>>1,r);
}

long long calc(int w,int h,int n,int m)
{
  int cnt=0,xn=0;
  seg[cnt++]={0,w,0,0};
  seg[cnt++]={0,w,h,INF};
  X[xn++]=0;
  X[xn++]=w;

  for (int i=0;i<n;i++)
  {
    seg[cnt++]={rec[i].x1-1,rec[i].x2,rec[i].y1-1,INF};
    seg[cnt++]={rec[i].x1-1,rec[i].x2,rec[i].y2,rec[i].y2};
    X[xn++]=rec[i].x1-1;
    X[xn++]=rec[i].x2;
  }

  sort(seg,seg+cnt);
  sort(X,X+xn);
  xn=unique(X,X+xn)-X;

  long long res=0;

  for (int i=0;i<cnt;i++)
  {
    int a=lower_bound(X,X+xn,seg[i].x1)-X;
    int b=lower_bound(X,X+xn,seg[i].x2)-X;
    if (seg[i].v==INF) res+=query(a,b,seg[i].y,m-1,0,0,xn);
    update(a,b,seg[i].v,0,0,xn);
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int w,h,n,m;

  while (scanf("%d%d%d%d",&w,&h,&n,&m)==4)
  {
    for (int i=0;i<n;i++) rec[i].read();

    long long res=calc(w,h,n,m);

    for (int i=0;i<n;i++) rec[i].rotate();

    if (m!=1) res+=calc(h,w,n,m);

    printf("%lld\n",res);
  }



  return 0;
}
