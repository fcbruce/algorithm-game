/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 09:42:51 PM CST
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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  scanf("%d %d",&n,&m);

  long long res=1;

  if (n>m) swap(n,m);

  long long cur=1;
  long long r=m;
  long long cut=0;

  while (cur<r)
  {
    if (cur+n-1==r)
    {
      res+=n-1-cut-cut;
      break;
    }
    else if (cur+n-1<r)
    {
      res+=n-1-cut-cut;
      cur+=n-1;
    }
    else
    {
      res+=n-1-cut-cut;
      cur+=n-1;
      cut++;
      r+=m-1;
    }
  }

  printf(lld "\n",res);


  return 0;
}
