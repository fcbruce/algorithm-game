/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Nov 2014 07:04:01 PM CST
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
#define maxn 20007

using namespace std;

int maxv[maxn<<2],addv[maxn<<2];

struct __line
{
  int a,b,h,v;
  bool operator < (const __line &_)const
  {
    if (h==_.h) return v>_.v;
    return h<_.h;
  }
}line[maxn];

int X[maxn];

inline void pushup(int k)
{
  maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

inline void pushdown(int k)
{
  if (addv[k])
  {
    int lc=k*2+1,rc=k*2+2;
    addv[lc]+=addv[k];maxv[lc]+=addv[k];
    addv[rc]+=addv[k];maxv[rc]+=addv[k];
    addv[k]=0;
  }
}

void update(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    addv[k]+=v;
    maxv[k]+=v;
    return ;
  }

  pushdown(k);
  update(a,b,v,k*2+1,l,l+r>>1);
  update(a,b,v,k*2+2,l+r>>1,r);
  pushup(k);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  
  while (scanf("%d",&n),n>=0)
  {
    int w,h;
    scanf("%d%d",&w,&h);
    
    int cnt=0,xn=0;
    for (int i=0,x,y;i<n;i++)
    {
      scanf("%d%d",&x,&y);
      line[cnt++]=(__line){x,x+w+1,y,1};
      line[cnt++]=(__line){x,x+w+1,y+h,-1};
      X[xn++]=x;
      X[xn++]=x+w+1;
    }

    sort(line,line+cnt);

    sort(X,X+xn);
    xn=unique(X,X+xn)-X;

    int MAX=0;
    memset(maxv,0,sizeof maxv);
    memset(addv,0,sizeof addv);

    for (int i=0;i<cnt;i++)
    {
      int a=lower_bound(X,X+xn,line[i].a)-X;
      int b=lower_bound(X,X+xn,line[i].b)-X;

      update(a,b,line[i].v,0,0,xn);
      MAX=max(MAX,maxv[0]);
    }

    printf("%d\n",MAX);
  }


  return 0;
}
