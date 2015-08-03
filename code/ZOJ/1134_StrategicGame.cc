/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 03 Aug 2015 08:38:57 PM CST
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

#define maxm 3007
#define maxn 1507

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

bool choice[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int dfs(int s,int fa)
{
  bool unchoice=true;
  choice[s]=false;
  int res=0;

  for (int e=fir[s];~e;e=nex[e]) if (fa!=v[e])
  {
    res+=dfs(v[e],s);
    unchoice&=choice[v[e]];
  }

  if (!unchoice)
  {
    res++;
    choice[s]=true;
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0,u,v,c;i<n;i++)
    {
      scanf("%d:(%d)",&u,&c);
      while (c--)
      {
        scanf("%d",&v);
        add_edge(u,v);
        add_edge(v,u);
      }
    }

    printf("%d\n",dfs(0,-1));
  }


  return 0;
}
