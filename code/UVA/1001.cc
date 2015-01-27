/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 26 Jan 2015 10:26:25 PM CST
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

double x[maxn],y[maxn],z[maxn],r[maxn];
double G[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  int n;

  while (scanf("%d",&n),n>=0)
  {
    n++;
    for (int i=1;i<n;i++) scanf("%lf%lf%lf%lf",x+i,y+i,z+i,r+i);
    scanf("%lf%lf%lf",x,y,z);
    scanf("%lf%lf%lf",x+n,y+n,z+n);
    r[0]=r[n]=0;

    for (int i=0;i<=n;i++) for (int j=0;j<=n;j++)
    {
      double dis=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]))-r[i]-r[j];
      G[i][j]=max(dis,0.0);
    }

    for (int k=0;k<=n;++k) for (int i=0;i<=n;++i) for (int j=0;j<=n;++j) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    printf("Cheese %d: Travel time = %.0f sec\n",++__,G[0][n]*10);
  }

  return 0;
}
