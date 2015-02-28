/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 28 Feb 2015 03:32:38 PM CST
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
#define maxn 107

using namespace std;

struct building
{
  int id;
  double x,y,w,d,h;
  bool operator < (const building &_) const
  {
    if (x==_.x) return y<_.y;
    return x<_.x;
  }
  void read(int i)
  {
    id=i;
    scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&d,&h);
  }
}b[maxn];

int n;

double x[maxn<<1];
int xn;

inline bool cover(int i,double pos)
{
  return b[i].x<=pos && pos<=b[i].x+b[i].w;
}

inline bool vis(int i,double pos)
{
  if (!cover(i,pos)) return false;

  for (int j=0;j<n;j++)
    if (b[j].y<b[i].y && b[j].h>=b[i].h && cover(j,pos)) return false;

  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d",&n),n!=0)
  {
    xn=0;
    for (int i=0;i<n;i++)
    {
      b[i].read(i+1);
      x[xn++]=b[i].x;
      x[xn++]=b[i].x+b[i].w;
    }

    sort(b,b+n);
    sort(x,x+xn);
    xn=unique(x,x+xn)-x;

    if (__>0) putchar('\n');
    printf("For map #%d, the visible buildings are numbered as follows:\n",++__);

    bool fir=true;
    for (int i=0;i<n;i++)
    {
      bool ok=false;
      for (int j=0;j<xn-1;j++) if (vis(i,(x[j]+x[j+1])/2.0))
      {
        ok=true;
        break;
      }

      if (ok)
      {
        if (!fir) putchar(' ');
        fir=false;
        printf("%d",b[i].id);
      }
    }
    putchar('\n');
  }

  return 0;
}
