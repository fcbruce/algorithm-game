/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 09:59:45 AM CST
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
#define maxn 1000007

using namespace std;

int n,m;
int a[maxn],b[maxn],nex[maxn];

inline void get_prefix()
{
  nex[0]=-1;
  for (int i=1,j=-1;i<m;i++)
  {
    while (j>-1 && b[j+1]!=b[i]) j=nex[j];
    if (b[j+1]==b[i]) j++;
    nex[i]=j;
  }
}

inline int kmp()
{
  int res=0;
  get_prefix();
  for (int i=0,j=-1;i<n;i++)
  {
    while (j>-1 && b[j+1]!=a[i]) j=nex[j];
    if (b[j+1]==a[i]) j++;
    if (j+1==m)
    {
      return i-j+1;
    }
  }
  return -1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",a+i);
    for (int i=0;i<m;i++) scanf("%d",b+i);
    printf("%d\n",kmp());
  }



  return 0;
}
