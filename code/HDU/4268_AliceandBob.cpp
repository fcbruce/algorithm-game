/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Nov 2014 07:15:35 PM CST
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
#define maxn 100007

using namespace std;

struct card
{
  int h,w;
  bool operator < (const card &_)const
  {
    if (h==_.h) return w<_.w;
    return h<_.h;
  }
}a[maxn],b[maxn];

multiset<int> SET;
multiset<int>::iterator it;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    SET.clear();
    scanf("%d",&n);
    for (int i=0;i<n;i++)
      scanf("%d%d",&a[i].h,&a[i].w);
    for (int i=0;i<n;i++)
      scanf("%d%d",&b[i].h,&b[i].w);

    sort(a,a+n);
    sort(b,b+n);

    int cnt=0;
    for (int i=0,j=0;i<n;i++)
    {
      while (j<n && b[j].h<=a[i].h)
      {
        SET.insert(b[j].w);
        j++;
      }

      it=SET.upper_bound(a[i].w);
      if (it!=SET.begin())
      {
        SET.erase(--it);
        cnt++;
      }
    }

    printf("%d\n",cnt);
  }

  return 0;
}
