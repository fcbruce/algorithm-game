/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-24 20:07:42 
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
#define maxn 

using namespace std;

int p,q,r,s,t,u;

double
func(double x)
{
  return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*sqr(x)+u;
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  while (~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u))
  {
    if (func(0)*func(1)>eps)
    {
      puts("No solution");
      continue;
    }
    
    double _l=0,_r=1;
    while (_r-_l>eps)
    {
      double mid=(_l+_r)/2;
      
      if (func(mid)>0)
        _l=mid;
      else
        _r=mid;
    }
    
    printf("%.4f\n",_l);
  }
  
  return 0;
}



