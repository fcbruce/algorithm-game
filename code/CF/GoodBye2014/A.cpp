/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 30 Dec 2014 10:59:28 PM CST
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
#define maxn 33333

using namespace std;

int a[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  int n;
  int t;
  scanf("%d%d",&n,&t);

  t--;
  for (int i=0;i<n-1;i++) scanf("%d",a+i);
  a[n-1]=INF;

  bool ok=false;
  for (int i=0;i<=t;i=i+a[i])
  {
    if (i==t) ok=true;
  }

  if (ok)puts("YES");
  else puts("NO");


  return 0;
}
