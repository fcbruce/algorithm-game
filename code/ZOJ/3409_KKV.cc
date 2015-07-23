/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 22 Jul 2015 01:54:44 PM CST
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
#define maxn 64

using namespace std;

inline int dcmp(double k)
{
  return fabs(k)<eps?0:k>0?1:-1;
}

struct point
{
  double x,y,z;
  point(){}
  point(double x,double y,double z):x(x),y(y),z(z){}
  void read()
  {
    scanf("%lf%lf%lf",&x,&y,&z);
  }
  void print()
  {
    printf("%.2f %.2f %.2f\n",x,y,z);
  }
  point operator + (const point rhs)
  {
    return point(x+rhs.x,y+rhs.y,z+rhs.z);
  }
  point operator - (const point rhs)
  {
    return point(x-rhs.x,y-rhs.y,z-rhs.z);
  }
  point operator / (const double rhs)
  {
    return point(x/rhs,y/rhs,z/rhs);
  }
  point operator * (const double rhs)
  {
    return point(x*rhs,y*rhs,z*rhs);
  }
  double operator / (const point rhs)
  {
    if (dcmp(x)!=0 && dcmp(rhs.x)!=0) return x/rhs.x;
    if (dcmp(y)!=0 && dcmp(rhs.y)!=0) return y/rhs.y;
    if (dcmp(z)!=0 && dcmp(rhs.z)!=0) return z/rhs.z;
    return 0;
  }
}p[maxn];

int n,M,m,m0,v0;

int circle_cross_line(point a,point b,point o,double r,point ret[])
{
  double x0=o.x,y0=o.y,z0=o.z;
  double x1=a.x,y1=a.y,z1=a.z;
  double x2=b.x,y2=b.y,z2=b.z;
  double dx=x2-x1,dy=y2-y1,dz=z2-z1;
  double A=sqr(dx)+sqr(dy)+sqr(dz);
  double B=2*dx*(x1-x0)+2*dy*(y1-y0)+2*dz*(z1-z0);
  double C=sqr(x1-x0)+sqr(y1-y0)+sqr(z1-z0)-sqr(r);
  double delta = B*B-4*A*C;
  if (dcmp(delta)<0) return 0;
  else if (dcmp(delta)==0)
  {
    double t=(-B)/(2*A);
    ret[0]=point(x1+t*dx,y1+t*dy,z1+t*dz);
    return 1;
  }
  else
  {
    double t1=(-B-sqrt(delta))/(2*A);
    double t2=(-B+sqrt(delta))/(2*A);
    ret[0]=point(x1+t1*dx,y1+t1*dy,z1+t1*dz);
    ret[1]=point(x1+t2*dx,y1+t2*dy,z1+t2*dz);
    return 2;
  }
}

double move()
{
  double res = 0;
  point v = {0,0,0};
  for (int i=0;i<n;i++)
  {
    point o=p[i]+v*M;
    point cp[2];
    int num = circle_cross_line(p[i],p[i+1],o,m0*v0,cp);
    if (num==0) return -1.0;
    point go;
    go = cp[num-1]-p[i];
    double k=go/(p[i+1]-p[i]);
    if (dcmp(k)<=0) return -1.0;
    M-=m0;
    v=go/M;
    res += (p[i+1]-p[i])/v;
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d%d%d%d",&n,&M,&m,&m0,&v0)==5)
  {
    p[0]={0,0,0};
    for (int i=1;i<=n;i++) p[i].read();

    double res = move();
    if (res < 0) puts("Another kind of KKV.");
    else printf("%.2f\n",res);
  }



  return 0;
}
