/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 28 Dec 2014 06:09:40 PM CST
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
#define maxn 32767

using namespace std;

int a[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn n;
  while (scanf("%d",&n)==1)
  {
    int cnt=0;
    memset(a,0x3f,sizeof a);
    for (int i=0,h;i<n;i++)
    {
      scanf("%d",&h);
      int id=lower_bound(a,a+cnt,h)-a;
      if (id==cnt)
      {
        a[cnt++]=h;
      }
      else
      {
        a[id]=h;
      }
    }

    printf("%d\n",cnt);
  }



  return 0;
}
