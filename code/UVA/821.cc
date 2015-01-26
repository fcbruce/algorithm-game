/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 26 Jan 2015 09:50:45 PM CST
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
#define maxn 111

using namespace std;

int G[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  int a,b;
  
  while (scanf("%d%d",&a,&b),a!=0 && b!=0)
  {
    memset(G,0x3f,sizeof G);
    G[a][b]=1;
    while (scanf("%d%d",&a,&b),a!=0 && b!=0) G[a][b]=1;
    for (int k=1;k<maxn;k++) for (int i=1;i<maxn;i++) for (int j=1;j<=maxn;j++) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    double res=0;int cnt=0;
    for (int i=1;i<maxn;i++) for (int j=1;j<maxn;j++) if (i!=j && G[i][j]<INF)
    {
      res+=G[i][j];
      cnt++;
    }

    printf("Case %d: average length between pages = %.3f clicks\n",++__,res/cnt);
  }

  return 0;
}
