/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-23 23:34:34 
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
#define maxn 10007

using namespace std;

long long l_r,l_g,l_b,l_rg,l_rb,l_gb,l_rgb;

struct __seg
{
  int l,r,h,type,col;
  bool operator < (const __seg &s)const
  {
    return h<s.h;
  }
}seg[maxn<<1];

int X[maxn<<1];

int sum_r[maxn<<2],sum_g[maxn<<2],sum_b[maxn<<2];
int col_r[maxn<<2],col_g[maxn<<2],col_b[maxn<<2];

inline void
pushup(int k,int l,int r)
{
  int lc=k*2+1,rc=k*2+2;
  
  sum_r[k]=sum_g[k]=sum_b[k]=0;
  
  if (r-l>1)
  {
    sum_r[k]=sum_r[lc]+sum_r[rc];
    sum_g[k]=sum_g[lc]+sum_g[rc];
    sum_b[k]=sum_b[lc]+sum_b[rc];
  }
  
  if (col_r[k]>0) sum_r[k]=X[r]-X[l];
  if (col_g[k]>0) sum_g[k]=X[r]-X[l];
  if (col_b[k]>0) sum_b[k]=X[r]-X[l];
}

void
update(int a,int b,int col,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    switch(col)
    {
      case 1:col_r[k]+=v;break;
      case 2:col_g[k]+=v;break;
      case 3:col_b[k]+=v;break;
    }
    pushup(k,l,r);

    return ;
  }
  
  update(a,b,col,v,k*2+1,l,l+r>>1);
  update(a,b,col,v,k*2+2,l+r>>1,r);
  
  pushup(k,l,r);
}

inline bool
judge(int k,int l,int r)
{
  return (sum_r[k]==X[r]-X[l] || sum_r[k]==0) && 
         (sum_g[k]==X[r]-X[l] || sum_g[k]==0) && 
         (sum_b[k]==X[r]-X[l] || sum_b[k]==0);
}

inline void
_plus(int k,int l,int r)
{
  int type=0;
  if (sum_r[k]==X[r]-X[l]) type|=1<<0;
  if (sum_g[k]==X[r]-X[l]) type|=1<<1;
  if (sum_b[k]==X[r]-X[l]) type|=1<<2;

  switch (type)
  {
    case 0:
      break;
    case 1:
      l_r+=X[r]-X[l];
      break;
    case 2:
      l_g+=X[r]-X[l];
      break;
    case 3:
      l_rg+=X[r]-X[l];
      break;
    case 4:
      l_b+=X[r]-X[l];
      break;
    case 5:
      l_rb+=X[r]-X[l];
      break;
    case 6:
      l_gb+=X[r]-X[l];
      break;
    case 7:
      l_rgb+=X[r]-X[l];
      break;
  }
}

inline void
pushdown(int k,int l,int r)
{
  int lc=k*2+1,rc=k*2+2,m=l+r>>1;
  
  col_r[lc]+=col_r[k];
  col_r[rc]+=col_r[k];

  col_g[lc]+=col_g[k];
  col_g[rc]+=col_g[k];

  col_b[lc]+=col_b[k];
  col_b[rc]+=col_b[k];
    
  pushup(lc,l,m);
  pushup(rc,m,r);
}

inline void
recover(int k,int l,int r)
{
  int lc=k*2+1,rc=k*2+2,m=l+r>>1;
  
  col_r[lc]-=col_r[k];
  col_r[rc]-=col_r[k];

  col_g[lc]-=col_g[k];
  col_g[rc]-=col_g[k];

  col_b[lc]-=col_b[k];
  col_b[rc]-=col_b[k];
  
  pushup(lc,l,m);
  pushup(rc,m,r);
}

void
query(int k,int l,int r)
{  
  if (judge(k,l,r))
  {
    _plus(k,l,r);
    return ;
  }
  
  pushdown(k,l,r);
  
  query(k*2+1,l,l+r>>1);
  query(k*2+2,l+r>>1,r);
  
  recover(k,l,r);
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T,__=0;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    int n;
    scanf("%d",&n);
    char _col;
    int x1,y1,x2,y2;
    int cnt=0,xn=0,col;
    for (int i=0;i<n;i++)
    {
      scanf(" %c%d%d%d%d",&_col,&x1,&y1,&x2,&y2);
      switch (_col)
      {
        case 'R':
          col=1;
          break;
        case 'G':
          col=2;
          break;
        case 'B':
          col=3;
          break;
      }
      seg[cnt++]=(__seg){x1,x2,y1,1,col};
      seg[cnt++]=(__seg){x1,x2,y2,-1,col};
      X[xn++]=x1;
      X[xn++]=x2;
    }
    
    sort(seg,seg+cnt);
    
    sort(X,X+xn);
    xn=unique(X,X+xn)-X;
    xn--;
    
    int last=0;
    long long a_r,a_g,a_b,a_rg,a_rb,a_gb,a_rgb;
    a_r=a_g=a_b=a_rg=a_rb=a_gb=a_rgb=0;
    
    memset(sum_r,0,sizeof sum_r);
    memset(sum_g,0,sizeof sum_g);
    memset(sum_b,0,sizeof sum_b);
    memset(col_r,0,sizeof col_r);
    memset(col_g,0,sizeof col_g);
    memset(col_b,0,sizeof col_b);
    
    for (int i=0;i<cnt;i++)
    {
      int a=lower_bound(X,X+xn,seg[i].l)-X;
      int b=lower_bound(X,X+xn,seg[i].r)-X;
      int col=seg[i].col,v=seg[i].type;
      
      l_r=l_g=l_b=l_rg=l_rb=l_gb=l_rgb=0;
      
      query(0,0,xn);
      
      a_r+=l_r*(seg[i].h-last);
      a_g+=l_g*(seg[i].h-last);
      a_b+=l_b*(seg[i].h-last);
      a_rg+=l_rg*(seg[i].h-last);
      a_rb+=l_rb*(seg[i].h-last);
      a_gb+=l_gb*(seg[i].h-last);
      a_rgb+=l_rgb*(seg[i].h-last);
      
      last=seg[i].h;
      
      update(a,b,col,v,0,0,xn);
    }
    
    printf("Case %d:\n",++__);
    
    printf(lld "\n",a_r);
    printf(lld "\n",a_g);
    printf(lld "\n",a_b);
    printf(lld "\n",a_rg);
    printf(lld "\n",a_rb);
    printf(lld "\n",a_gb);
    printf(lld "\n",a_rgb);
  }
  
  return 0;
}



