/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 27 Dec 2014 07:04:56 PM CST
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

int a[2333];

bool judge(int x)
{
  for (int i=1;i<x;i++)
    if (__gcd(i,x)>1) return false;
  return true;
}

void init()
{
  for (int i=1;i<1001;i++)
  {
    if (judge(i)) a[i]=i;
    else a[i]=0;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  init();

  int n;
  while (scanf("%d",&n)==1)
  {
    int res=0;
    for (int i=0,x;i<n;i++)
    {
      scanf("%d",&x);
      res+=a[x];
    }
    printf("%d\n",res);
  }


  return 0;
}
