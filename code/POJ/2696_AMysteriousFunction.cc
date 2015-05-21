/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 20 May 2015 07:24:31 PM CST
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
#define maxn 1007

using namespace std;

int a,b,c,d,e,f,g,h,i;
bool vis[maxn];
int res[maxn];

int func(int i)
{
  if (vis[i]) return res[i];

  switch (i)
  {
    case 0:
      vis[i]=true;
      return res[i]=a;
      break;
    case 1:
      vis[i]=true;
      return res[i]=b;
      break;
    case 2:
      vis[i]=true;
      return res[i]=c;
      break;
    default:
      if (i&1)
      {
        vis[i]=true;
        return res[i]=((d*func(i-1)+e*func(i-2)-f*func(i-3))%g+g)%g;
      }
      else
      {
        vis[i]=true;
        return res[i]=((f*func(i-1)-d*func(i-2)+e*func(i-3))%h+h)%h;
      }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    memset(vis,0,sizeof vis);
    scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);

    printf("%d\n",func(i));
  }



  return 0;
}
