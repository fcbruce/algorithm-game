/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 06:03:38 PM CST
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

multiset<long long> s;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,k;
  while (scanf("%d%d",&n,&k)==2)
  {
    s.clear();
    while (n--)
    {
      char op;
      scanf(" %c",&op);

      if (op=='Q')
      {
        printf(lld"\n",*s.begin());
      }
      else
      {
        long long v;
        scanf(lld,&v);
        s.insert(v);
        if (s.size()>k) s.erase(s.begin());
      }
    }
  }




  return 0;
}
