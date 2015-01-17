/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 17 Jan 2015 02:33:40 PM CST
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
#define maxn 1111

using namespace std;

int pre[maxn];
bool __fixed[maxn];

struct __lap
{
  int x,y;
}lap[maxn];

double dis(__lap &a,__lap &b)
{
  return sqrt(sqr((double)a.x-b.x)+sqr((double)a.y-b.y));
}

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline void merge(int a,int b)
{
  pre[root(a)]=root(b);
}

inline bool same(int a,int b)
{
  return root(a)==root(b);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,d;

  scanf("%d%d",&n,&d);
  
  for (int i=1;i<=n;i++) pre[i]=i;
  memset(__fixed,0,sizeof __fixed);

  for (int i=1,x,y;i<=n;i++)
  {
    scanf("%d%d",&x,&y);
    lap[i]={x,y};
  }

  char op;
  while (scanf(" %c",&op)==1)
  {
    if (op=='O')
    {
      int id;
      scanf("%d",&id);
      if (__fixed[id]) continue;
      __fixed[id]=true;
      for (int i=1;i<=n;i++)
      {
        if (__fixed[i] && dis(lap[i],lap[id])<d+eps)
          merge(i,id);
      }
    }
    else
    {
      int a,b;
      scanf("%d%d",&a,&b);
      if (same(a,b)) puts("SUCCESS");
      else puts("FAIL");
    }
     
  }


  return 0;
}
