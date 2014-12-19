/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 30 Oct 2014 10:42:54 AM CST
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

bool vis[maxn];

struct task
{
  int s,d;
  bool operator < (const task &_)const
  {
    return s>_.s;
  }
}t[maxn];

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
    scanf("%d",&n);

    for (int i=0;i<n;i++)
      scanf("%d",&t[i].d);
    for (int i=0;i<n;i++)
      scanf("%d",&t[i].s);
  
    sort(t,t+n);
    memset(vis,0,sizeof vis);
    int reduce=0;

    for (int i=0;i<n;i++)
    {
      bool done=false;
      for (int j=min(t[i].d,n);j>0;j--)
      {
        if (!vis[j])
        {
          vis[j]=true;
          done=true;
          break;
        }
      }

      if (!done) reduce+=t[i].s;
    }

    printf("%d\n",reduce);
  }

  return 0;
}
