/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 21 Feb 2015 08:42:52 PM CST
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

set<long long> s1,s2;

int a[]={2,3,5};

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  s1.insert(1);
  s2.insert(1);

  for (int i=1;i<1500;i++)
  {
    long long x=*s1.begin();
    s1.erase(x);

    for (int j=0;j<3;j++)
    {
      long long y=x*a[j];
      if (s2.count(y)==0)
      {
        s1.insert(y);
        s2.insert(y);
      }
    }
  }

  printf("The 1500'th ugly number is " lld ".\n",*s1.begin());



  return 0;
}
