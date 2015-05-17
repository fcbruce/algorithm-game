/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 10:34:53 AM CST
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
#define maxn 1444

using namespace std;

bool work[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  while (scanf("%d",&n)==1)
  {
    memset(work,0,sizeof work);
    while (n--)
    {
      int h1,h2,m1,m2;
      scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
      memset(work+h1*60+m1,1,sizeof(bool)*(h2*60+m2-h1*60-m1));
    }
    int cnt=0;
    for (int i=0;i<1440;i++) if (!work[i]) cnt++;
    printf("%d\n",cnt);
  }



  return 0;
}
