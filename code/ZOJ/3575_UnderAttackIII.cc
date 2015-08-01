/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 01 Aug 2015 07:21:58 PM CST
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
#define eps 1e-7

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 404

using namespace std;

double a,b;
int n;

inline int dcmp(double k)
{
  return fabs(k)<eps ? 0 : k>0 ? 1 : -1;
}

struct point
{
  double x,y;
  point() {}
  point (double x,double y):x(x),y(y) {}
  void read()
  {
    scanf("%lf%lf",&x,&y);
    x/=a;
    y/=b;
  }
  double dis(point rhs)
  {
    return sqrt(sqr(x-rhs.x)+sqr(y-rhs.y));
  }
  point operator + (point rhs)
  {
    return {x+rhs.x,y+rhs.y};
  }
  point operator - (point rhs)
  {
    return {x-rhs.x,y-rhs.y};
  }
  point operator * (double rhs)
  {
    return {x*rhs,y*rhs};
  }
  point operator / (double rhs)
  {
    return {x/rhs,y/rhs};
  }
  point norm()
  {
    double l=this->dis({0,0});
    return {-y/l,x/l};
  }
}p[maxn];

int calc(point o)
{
  int res=0;
  for (int i=0;i<n;i++) if (dcmp(o.dis(p[i])-1)<=0) res++;
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%lf%lf",&a,&b)==2)
  {
    scanf("%d",&n);
    for (int i=0;i<n;i++) p[i].read();

    int res=1;
    for (int i=0;i<n;i++) for (int j=0;j<i;j++)
    {
      double dis=p[i].dis(p[j]);
      if (dcmp(dis-2)>0) continue;
      point dx=(p[i]-p[j])/2;
      double len=sqrt(4.0-sqr(dis));
      point dy=(p[i]-p[j]).norm()*len/2.0;
      res=max(res,max(calc(p[j]+dx+dy),calc(p[j]+dx-dy)));
    }

    printf("%d\n",res);
  }



  return 0;
}
