/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 08 Nov 2014 11:49:16 PM CST
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
#define maxn 2333

using namespace std;

long long G[maxn][maxn],a[maxn][maxn],b[maxn][maxn],c[maxn][maxn],d[maxn][maxn];
long long MAX[2];
int x[2],y[2];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      scanf(lld,&G[i][j]);

  memset(a,0,sizeof a);
  memset(b,0,sizeof a);
  memset(c,0,sizeof a);
  memset(d,0,sizeof a);

  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
      a[i][j]=a[i-1][j-1]+G[i][j];
      b[i][j]=b[i-1][j+1]+G[i][j];
    }
  
  for (int i=n;i>0;i--)
    for (int j=1;j<=n;j++)
    {
      c[i][j]=c[i+1][j-1]+G[i][j];
      d[i][j]=d[i+1][j+1]+G[i][j];
    }

  MAX[0]=MAX[1]=0;
  
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
      int id=(i+j)&1;
      long long temp=a[i][j]+b[i][j]+c[i][j]+d[i][j]-3*G[i][j];
      if (temp>=MAX[id])
      {
        MAX[id]=temp;
        x[id]=i;
        y[id]=j;
      }
    }

  printf(lld"\n",MAX[0]+MAX[1]);
  printf("%d %d %d %d\n",x[0],y[0],x[1],y[1]);



  return 0;
}
