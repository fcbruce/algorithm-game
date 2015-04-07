/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 06 Apr 2015 06:38:50 PM CST
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
#define maxn 1000007

using namespace std;

bool vis[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(vis,0,sizeof vis);

  for (int i=0;i<1000001;i++)
  {
    int res=i;
    int k=i;
    while (k!=0)
    {
      res+=k%10;
      k/=10;
    }
    vis[res]=true;
  }

  for (int i=1;i<1000001;i++) if (!vis[i])printf("%d\n",i);




  return 0;
}
