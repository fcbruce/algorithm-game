/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 22 Feb 2015 03:06:12 PM CST
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

#define maxm 17
#define maxn 10007

using namespace std;

long long data[maxn][maxm];

map<pair<LL,LL>,int> MAP;

LL read()
{
  int c;
  while (c=getchar(),c==' ' || c=='\n' || c==',') ;

  long long v=c;
  while (c=getchar(),c!='\n' && c!=',' && c>-1)
  {
    v=v*131+c;
  }

  return v;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  while (scanf("%d%d",&n,&m)==2)
  {
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
      data[i][j]=read();

    for (int i=1;i<=m;i++) for (int j=i+1;j<=m;j++) 
    {
      MAP.clear();
      for (int k=1;k<=n;k++)
      {
        pair<LL,LL> p={data[k][i],data[k][j]};
        if (MAP.count(p)>0)
        {
          puts("NO");
          printf("%d %d\n",MAP[p],k);
          printf("%d %d\n",i,j);
          goto end;
        }
        else MAP[p]=k;
      }
    }

    puts("YES");
end:;
  }



  return 0;
}
