/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 06 Apr 2015 06:05:18 PM CST
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

double a[maxn],b[maxn],c[maxn];
int n;

int dcmp(double x,double y)
{
  if (fabs(x-y)<eps) return 0;
  if (x>y) return 1;
  return -1;
}

double f(double x)
{
  double res=-1e20;
  for (int i=0;i<n;i++)
  {
    res=max(res,a[i]*(sqr(x))+b[i]*x+c[i]);
  }
  return res;
}

double calc()
{
  double l=0,r=1000;

  double res;

  while (dcmp(l,r)<0)
  {
    double mid=(l+r)/2.0;
    double mmid=(mid+r)/2.0;

    double lr=f(mid);
    double rr=f(mmid);

    if (dcmp(lr,rr)<0)
    {
      res=lr;
      r=mmid;
    }
    else
    {
      res=rr;
      l=mid;
    }
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d",&n);

    double res=1e20;

    for (int i=0;i<n;i++)
    {
      scanf("%lf %lf %lf",a+i,b+i,c+i);
    }

    printf("%.4f\n",calc());
  }



  return 0;
}
