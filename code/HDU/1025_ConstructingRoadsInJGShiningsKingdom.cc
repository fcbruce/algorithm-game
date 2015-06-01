/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 01 Jun 2015 11:55:42 PM CST
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
#define maxn 500007

using namespace std;

int a[maxn],h[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  int n;

  while (scanf("%d",&n)==1)
  {
    for (int i=0,u,v;i<n;i++) 
    {
      scanf("%d%d",&u,&v);
      a[--u]=v;
    }

    memset(h,0x3f,sizeof h);
    int j=0;
    for (int i=0;i<n;i++)
    {
      int *p=lower_bound(h,h+j,a[i]);
      *p=a[i];
      if (h[j]!=INF) j++;
    }

    printf("Case %d:\n",++__);
    printf("My king, at most %d road%s can be built.\n\n",j,j>1?"s":"");
  }


  return 0;
}
