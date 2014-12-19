/*
 *
 * Author : fcbruce
 *
 * Time : Wed 01 Oct 2014 11:55:17 AM CST
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
#define maxn 233 

using namespace std;

double _x0,_y0,v0,theta,t,g,R;
int n;

int dcmp(double k)
{
  return k < -eps ? -1 : k > eps ? 1 : 0; 
}

struct point
{
  double x,y;
  point() {}
  point(double a,double b):x(a),y(b) {}
  void input()
  {
    scanf("%lf %lf",&x,&y);
  }
  bool operator < (const point &a)const
  {
    return dcmp(x-a.x)<0 || dcmp(x-a.x)==0 && dcmp(y-a.y)<0;
  }
  friend point operator - (const point &a,const point &b)
  {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator * (const point &a,const double &b)
  {
    return point(a.x * b, a.y * b);
  }
  friend point operator * (const double &b,const point &a)
  {
    return point(a.x * b, a.y * b);
  }
  friend point operator / (const point &a,const double &b)
  {
    return point(a.x / b, a.y / b);
  }
}res[maxn],cir;


double dot(const point &a,const point &b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(const point &a,const point &b)
{
  return a.x * b.y - a.y * b.x;
}

double abs(const point &o)
{
  return sqrt(dot(o,o));
}

point crosspt(const point &a,const point &b,const point &p,const point &q)
{
  double a1 = cross(b - a, p - a);
  double a2 = cross(b - a, q - a);
  return (p * a2 - q * a1) / (a2 - a1);
}

double mysqrt(double n)
{
  return sqrt(max(0.0,n));
}

double sector_area(const point &a,const point &b)
{
  double theta = atan2(a.y,a.x) - atan2(b.y,b.x);
  while (theta < eps) theta += 2*PI;
  while (theta > 2*PI + eps) theta -= 2*PI;
  theta = min(theta,2*PI - theta);
  return sqr(R) * theta / 2;
}

void circle_cross_line(point a,point b,point o,double r,point ret[],int &num)
{
  double x0 = o.x, y0 = o.y;
  double x1 = a.x, y1 = a.y;
  double x2 = b.x, y2 = b.y;
  double dx = x2 - x1, dy = y2 - y1;
  double A = sqr(dx) + sqr(dy);
  double B = 2*dx*(x1 - x0) + 2*dy*(y1 - y0);
  double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
  double delta = sqr(B) - 4*A*C;
  num=0;
  if (dcmp(delta) >= 0)
  {
    double t1 = (-B - mysqrt(delta)) / (2*A);
    double t2 = (-B + mysqrt(delta)) / (2*A);

    if (dcmp(t1 - 1) <= 0 && dcmp(t1) >= 0)
      ret[num++] = point(x1 + t1*dx, y1 + t1*dy);

    if (dcmp(t2 - 1) <= 0 && dcmp(t2) >= 0)
      ret[num++] = point(x1 + t2*dx, y1 + t2*dy);
  }
}

double calc(const point &a,const point &b)
{
  point p[2];
  int num=0;
  bool ina = dcmp(abs(a) - R) < 0;
  bool inb = dcmp(abs(b) - R) < 0;

  if (ina)
  {
    if (inb)
    {
      return abs(cross(a,b)) / 2.0;
    }
    else
    {
      circle_cross_line(a,b,point(0,0),R,p,num);
      return sector_area(b,p[0]) + abs(cross(a,p[0])) / 2.0;
    }
  }
  else
  {
    if (inb)
    {
      circle_cross_line(a,b,point(0,0),R,p,num);
      return sector_area(p[0],a) + abs(cross(p[0],b)) / 2.0;
    }
    else
    {
      circle_cross_line(a,b,point(0,0),R,p,num);
      if (num == 2)
        return sector_area(a,p[0]) + sector_area(p[1],b) + abs(cross(p[0],p[1])) / 2.0;
      else
        return sector_area(a,b);
    }
  }
}

double area()
{
  double ret = 0;
  for (int i=0;i<n;i++)
  {
    int sgn=dcmp(cross(res[i],res[i+1]));
    if (sgn!=0)
      ret+=sgn*calc(res[i],res[i+1]);
  }

  return ret;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%lf %lf %lf %lf %lf %lf %lf",&_x0,&_y0,&v0,&theta,&t,&g,&R)
        ,dcmp(_x0)||dcmp(_y0)||dcmp(v0)||dcmp(theta)||dcmp(t)||dcmp(g)||dcmp(R))
  {
    double alpha=theta*PI/180;
    double vx=v0*cos(alpha);
    double vy=v0*sin(alpha);
    
    cir.x=_x0+vx*t;
    cir.y=_y0+vy*t-.5*g*sqr(t);

    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
      res[i].input();
      res[i]=res[i]-cir;
    }

    cir.x=cir.y=0;
//
//    sort(res,res+n);
//    reverse(res,res+n);

    res[n]=res[0];

    printf("%.2f\n",area());
  }


  return 0;
}
