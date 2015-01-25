/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 28 Nov 2014 03:06:52 PM CST
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
#define maxn 10000

using namespace std;

int dig[10];
int ans[maxn][10];

void init()
{
  memset(dig,0,sizeof dig);
  
  for (int i=1;i<maxn;i++)
  {
    int k=i;
    while (k)
    {
      dig[k%10]++;
      k/=10;
    }
    memcpy(ans[i],dig,sizeof dig);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  init();

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    printf("%d",ans[n][0]);
    for (int i=1;i<10;i++) printf(" %d",ans[n][i]);
    puts("");
  }

  return 0;
}
