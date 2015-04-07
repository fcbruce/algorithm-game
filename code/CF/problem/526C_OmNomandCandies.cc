/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Apr 2015 01:21:14 AM CST
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

long long c,hr,hb,wr,wb;

long long calc(long long x)
{
  return x*hr+(c-x*wr)/wb*hb;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf(lld lld lld lld lld,&c,&hr,&hb,&wr,&wb);

  long long res=0;
  for (int a=0;a<2;a++) {
    long long cr=c/wr;
    res=max(res,calc(cr));

    for (int i=0;i<100000 ;i++)
    {
      cr--;
      if (cr<0) break ;
      res=max(res,calc(cr));
    }
    swap(wr,wb);
    swap(hr,hb);
  }

  printf(lld"\n",res);




  return 0;
}
