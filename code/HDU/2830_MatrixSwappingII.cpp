/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 28 Oct 2014 01:14:57 PM CST
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
#define maxn 1007

using namespace std;

char str[maxn];
int h[maxn],h_[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  while (scanf("%d%d",&n,&m)==2)
  {
    int MAX=0;
    memset(h,0,sizeof h);
    for (int i=0;i<n;i++)
    {
      scanf("%s",str);
      for (int j=0;j<m;j++)
        if (str[j]=='1') h[j]++;
        else h[j]=0;

      memcpy(h_,h,sizeof h);
      sort(h_,h_+m);
      for (int j=0;j<m;j++)
        MAX=max(MAX,(m-j)*h_[j]);
    }

    printf("%d\n",MAX);
  }


  return 0;
}
