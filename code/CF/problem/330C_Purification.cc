/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 06 Apr 2015 07:39:48 PM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>909053695
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

#define maxm 100007
#define maxn 207

using namespace std;

char g[maxn][maxn];
int r[maxn],c[maxn];
int n;

inline bool possible()
{
  int rr=0,cc=0;
  for (int i=1;i<=n;i++)
  {
    if (r[i]==n) rr++;
    if (c[i]==n) cc++;
  }

  if (rr==0)
  {
    for (int i=1;i<=n;i++)
    {
      for (int j=1;j<=n;j++) if (g[i][j]=='.')
      {
        printf("%d %d\n",i,j);
        break;
      }
    }
    return true;
  }
  if (cc==0)
  {
    for (int i=1;i<=n;i++)
    {
      for (int j=1;j<=n;j++) if (g[j][i]=='.')
      {
        printf("%d %d\n",j,i);
        break;
      }
    }
    return true;
  }
  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d",&n);

  for (int i=1;i<=n;i++)
    scanf("%s",g[i]+1);

  memset(r,0,sizeof r);
  memset(c,0,sizeof c);

  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=n;j++)
      if (g[i][j]=='E')
      {
        r[i]++;
        c[j]++;
      }
  }

  if (!possible())
    puts("-1");

  return 0;
}
