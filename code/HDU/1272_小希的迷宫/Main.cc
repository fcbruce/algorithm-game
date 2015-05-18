/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 18 May 2015 04:51:22 PM CST
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
#define maxn 100000

using namespace std;

int pre[maxn];
bool vis[maxn];
int cnt;

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int x,int y)
{
  return root(x)==root(y);
}

inline void merge(int u,int v)
{
  if (same(u,v)) return ;
  pre[root(v)]=root(u);
  cnt--;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int u,v;
  while (scanf("%d %d",&u,&v)==2)
  {
    if (u==-1 && v==-1) break;
    for (int i=0;i<maxn;i++) pre[i]=i;
    cnt=0;
    memset(vis,0,sizeof vis);
    bool ok=true;

    while (u!=0 && v!=0)
    {
      if (!vis[u]) { vis[u]=true; cnt++; }
      if (!vis[v]) { vis[v]=true; cnt++; }
      if (same(u,v)) ok=false;
      merge(u,v);
      scanf("%d %d",&u,&v);
    }

    if (cnt>1) ok=false;
    puts(ok?"Yes":"No");
  }



  return 0;
}
