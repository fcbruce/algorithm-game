/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Apr 2015 12:39:34 AM CST
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
#define maxn 

using namespace std;

char s[233];
int n;

bool ok(int p)
{
  for (int i=1;i<n;i++) 
  {
    int cnt=0;
    for (int j=0;j<5;j++) if (s[p+i*j]=='*')
    {
      cnt++;
    }
    if (cnt==5) return true;
  }
  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d",&n);

  scanf("%s",s);

  for (int i=0;i<n;i++)
  {
    if (ok(i))
    {
      printf("yes\n");
      return 0;
    }
  }

  puts("no");




  return 0;
}
