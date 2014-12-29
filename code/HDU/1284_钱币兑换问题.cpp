/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 28 Dec 2014 06:14:47 PM CST
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
#define maxn 44444

using namespace std;

long long ans[maxn][4];

void init()
{
  memset(ans,0,sizeof ans);
  ans[0][0]=1;
  for (int i=1;i<32768;i++)
    for (int j=0;j<4;j++)
      if (i-j>=0)
        for (int k=j;k<4;k++)
          if (i>=k && k>0)
            ans[i][k]+=ans[i-k][j];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  init();
  int n;
  while (scanf("%d",&n)==1)
  {
    printf(lld"\n",ans[n][1]+ans[n][2]+ans[n][3]);
  }


  return 0;
}
