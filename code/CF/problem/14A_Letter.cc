/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Apr 2015 06:04:36 PM CST
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
#define maxn 55

using namespace std;

char g[maxn][maxn];
int n,m;

bool spl(int l)
{
  for (int i=0;i<m;i++) if (g[l][i]=='*') return false;
  return true;
}

bool sph(int l)
{
  for (int i=0;i<n;i++) if (g[i][l]=='*') return false;
  return true;
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  scanf("%d%d",&n,&m);

  for (int i=0;i<n;i++)
    scanf("%s",g[i]);

  int a,b,c,d;
  a=b=0;
  c=n-1;
  d=m-1;

  for (;a<n;a++) if (!spl(a)) break;
  for (;c>a;c--) if (!spl(c)) break;
  for (;b<m;b++) if (!sph(b)) break;
  for (;d>b;d--) if (!sph(d)) break;

  for (int i=a;i<=c;i++) 
  {
    for (int j=b;j<=d;j++) putchar(g[i][j]);
    puts("");
  }


  return 0;
}
