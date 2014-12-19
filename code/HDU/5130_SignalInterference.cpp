/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 16 Dec 2014 10:37:16 AM CST
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
#define maxn 507

using namespace std;

inline int dcmp(double k)
{
  return k<-eps?-1:k>eps?1:0;
}

struct point
{
  double x,y;
  point(){}
  point(double a,double b):x(a),y(b){}

  friend point operator + (const point &a,const point &b)
  {
    return point(a.x+b.x,a.y+b.y);
  }
  friend point operator - (const point &a,const point &b)
  {
    return point(a.x-b.x,a.y-b.y);
  }
  friend point operator * (const point &a,const double &b)
  {
    return point(a.x*b,a.y*b);
  }
  friend point operator * (const double &a,const point &b)
  {
    return point(a*b.x,a*b.y);
  }
  friend point operator / (const point &a,const double &b)
  {
    return point(a.x/b,a.y/b);
  }
}res[maxn];

int n;
double r;

inline double dot(const point &a,const point &b)
{
  return a.x*b.x+a.y*b.y;
}

inline double cross(const point &a,const point &b)
{
  return a.x*b.y-a.y*b.x;
}

inline double abs(const point &o)
{
  return sqrt(dot(o,o));
}

inline double mysqrt(double n)
{
  return sqrt(max(0.0,n));
}

point crosspt(const point &a,const point &b,const point &p,const point &q)
{
  double a1=cross(b-a,p-a);
  double a2=cross(b-a,q-a);
  return (p*a2-q*a1)/(a2-a1);
}

void circle_cross_line(const point &a,const point &b,const point &o,double r,point ret[],int &num)
{
  double x0=o.x,y0=o.y;
  double x1=a.x,y1=a.y;
  double x2=b.x,y2=b.y;
  double dx=x2-x1,dy=y2-y1;
  double A=sqr(dx)+sqr(dy);
  double B=2*dx*(x1-x0)+2*dy*(y1-y0);
  double C=sqr(x1-x0)+sqr(y1-y0)-sqr(r);
  double delta=sqr(B)-4*A*C;
  num=0;
  if (dcmp(delta)>=0)
  {
    double t1=(-B-mysqrt(delta))/(2.0*A);
    double t2=(-B+mysqrt(delta))/(2.0*A);
    if (dcmp(t1-1)<=0 && dcmp(t1)>=0)
    {
      ret[num++]=point(x1+t1*dx,y1+t1*dy);
    }
    if (dcmp(t2-1)<=0 && dcmp(t2)>=0)
    {
      ret[num++]=point(x1+t2*dx,y1+t2*dy);
    }
  }
}

double sector_area(const point &a,const point &b)
{
  double theta=atan2(a.y,a.x)-atan2(b.y,b.x);
  while (theta<=0) theta+=2*PI;
  while (theta>2*PI) theta-=2*PI;
  theta=min(theta,2*PI-theta);
  return sqr(r)*theta/2.0;
}

double calc(const point &a,const point &b)
{
  point p[2];
  int num=0;
  bool ina=dcmp(abs(a)-r)<0;
  bool inb=dcmp(abs(b)-r)<0;
  if (ina)
  {
    if (inb)
    {
      return fabs(cross(a,b))/2.0;
    }
    else
    {
      circle_cross_line(a,b,point(0,0),r,p,num);
      return sector_area(b,p[0])+fabs(cross(a,p[0]))/2.0;
    }
  }
  else
  {
    if (inb)
    {
      circle_cross_line(a,b,point(0,0),r,p,num);
      return sector_area(p[0],a)+fabs(cross(p[0],b))/2.0;
    }
    else
    {
      circle_cross_line(a,b,point(0,0),r,p,num);
      if (num==2)
      {
        return sector_area(a,p[0])+sector_area(p[1],b)+fabs(cross(p[0],p[1]))/2.0;
      }
      else
      {
        return sector_area(a,b);
      }
    }
  }
}

double area()
{
  double ret=0;
  for (int i=0;i<n;i++)
  {
    int sgn=dcmp(cross(res[i],res[i+1]));
    if (sgn!=0)
    {
      ret+=sgn*calc(res[i],res[i+1]);
    }
  }
  return ret;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  double k;
  int __=0;

  while (scanf("%d %lf",&n,&k)==2)
  {
    for (int i=0;i<n;i++) scanf("%lf %lf",&res[i].x,&res[i].y);

    double xa,xb,ya,yb;
    scanf("%lf %lf",&xa,&ya);
    scanf("%lf %lf",&xb,&yb);

    double A=1.0-sqr(k);
    double E=2*xb-2*sqr(k)*xa;
    double F=2*yb-2*sqr(k)*ya;
    double G=sqr(k*xa)+sqr(k*ya)-sqr(xb)-sqr(yb);

    E/=A;
    F/=A;
    G/=A;

    double x0=E/2.0;
    double y0=F/2.0;
    r=G+sqr(E)/4.0+sqr(F)/4.0;
    r=sqrt(r);

    for (int i=0;i<n;i++)
    {
      res[i].x-=x0;
      res[i].y-=y0;
    }

    res[n]=res[0];

    printf("Case %d: %.10f\n",++__,fabs(area()));
    
  }


  return 0;
}
