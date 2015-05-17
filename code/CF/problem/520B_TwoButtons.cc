/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 07 Apr 2015 08:19:34 PM CST
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
#define maxn 20007

using namespace std;

pair<int,int> q[maxn<<3];
bool vis[maxn];

int bfs(int s,int t)
{
  int f,r;
  q[f=r=0]={s,0};
  vis[s]=true;

  while (f<=r)
  {
    auto x=q[f++];
    if (x.first==t) return x.second;

    int v1=x.first-1;
    if (v1>=0 && !vis[v1])
    {
      q[++r]={v1,x.second+1};
      vis[v1]=true;
    }
    
    int v2=x.first<<1;
    if (v2<maxn && !vis[v2])
    {
      q[++r]={v2,x.second+1};
      vis[v2]=true;
    }
  }
  return -1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(vis,0,sizeof vis);

  int n,m;
  scanf("%d%d",&n,&m);

  printf("%d\n",bfs(n,m));



  return 0;
}
