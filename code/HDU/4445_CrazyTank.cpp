/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 19 Nov 2014 07:41:44 PM CST
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
#define maxn 200

using namespace std;

const double g = 9.8;

int n;
double v[maxn];
double l1,l2,r1,r2,h;

int dcmp(double a,double b)
{
  if (fabs(a-b)<eps) return 0;
  return a<b?-1:1;
}

inline bool inc(double a,double b,double c)
{
  return dcmp(a,b)<=0 && dcmp(b,c)<=0;
}

int calc(double a)
{
  int cnt=0;
  for (int i=0;i<n;i++)
  {
    double vx=v[i]*cos(a);
    double vy=v[i]*sin(a);

    double t=(sqrt(sqr(vy)+2*g*h)-vy)/g;
    double l=vx*t;

    if (inc(l2,l,r2)) return 0;
    if (inc(l1,l,r1)) cnt++;
  }

  return cnt;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  double add=PI/1000.0;

  while (scanf("%d",&n),n!=0)
  {
    scanf("%lf%lf%lf%lf%lf",&h,&l1,&r1,&l2,&r2);
    for (int i=0;i<n;i++) scanf("%lf",v+i);
    
    int MAX=0;
    for (double angle=-PI/2;angle<PI/2;angle+=add)
      MAX=max(MAX,calc(angle));
    
    printf("%d\n",MAX);
  }
  


  return 0;
}
