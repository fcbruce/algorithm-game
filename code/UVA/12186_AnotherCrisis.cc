/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Aug 2015 06:51:40 PM CST
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

int n,p;

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

vector<int> save[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int dfs(int s)
{
  if (fir[s]==-1) return 1;

  int cnt=0;
  save[s].clear();
  for (int e=fir[s];~e;e=nex[e])
  {
    save[s].push_back(dfs(v[e]));
    cnt++;
  }
  cnt*=p;
  if (cnt%100==0) cnt/=100;
  else cnt=cnt/100+1;

  sort(save[s].begin(),save[s].end());
  int res=0;
  for (int i=0;i<cnt;i++) res+=save[s][i];
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&p)==2 && n!=0 && p!=0)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,fa;i<=n;i++)
    {
      scanf("%d",&fa);
      add_edge(fa,i);
    }

    printf("%d\n",dfs(0));
  }



  return 0;
}
