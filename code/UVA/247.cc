/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 16 Jan 2015 09:07:34 AM CST
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
#define maxn 30

using namespace std;

bool G[maxn][maxn];
char str[maxn][maxn];
char s1[maxn],s2[maxn];
bool vis[maxn];

map<string,int> MAP;

int cnt;

inline void init()
{
  memset(G,0,sizeof G);
  memset(vis,0,sizeof vis);
  MAP.clear();
  cnt=0;
}

inline int get_id(const char *s)
{
  string temp(s);
  if (MAP.find(temp)==MAP.end())
  {
    strcpy(str[cnt],s);
    MAP.insert({temp,cnt++});
  }
  return MAP[temp];

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  bool first=true;
  int n,m;

  while (scanf("%d%d",&n,&m),n!=0 && m!=0)
  {
    init();

    for (int i=0;i<m;i++)
    {
      scanf("%s %s",s1,s2);
      G[get_id(s1)][get_id(s2)]=true;
    }

    for (int k=0;k<n;k++)
      for (int i=0;i<n;i++)
        if (G[i][k])
          for (int j=0;j<n;j++)
            G[i][j]|=G[i][k]&&G[k][j];

    if (!first) puts("");
    first=false;
    printf("Calling circles for data set %d:\n",++__);
    for (int i=0;i<n;i++)
    {
      if (vis[i]) continue;
      vis[i]=true;
      printf("%s",str[i]);
      for (int j=0;j<n;j++)
      {
        if (vis[j]) continue;
        if (!G[i][j] || !G[j][i]) continue;
        vis[j]=true;
        printf(", %s",str[j]);
      }
      puts("");
    }

  }


  return 0;
}
