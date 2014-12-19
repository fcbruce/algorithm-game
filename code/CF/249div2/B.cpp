/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 06 Nov 2014 11:01:16 AM CST
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

char s[20];

int main()
{
#ifdef FCBRUCE
//  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int k;
  scanf("%s %d",s,&k);
  int l=strlen(s);

  for (int i=0;i<l && k>0;i++)
  {
    int v=i;
    for (int j=i+1;j<=i+k && j<l;j++)
      if (s[v]<s[j]) v=j;

    k-=v-i;
    for (int j=v;j>i;j--)
      swap(s[j],s[j-1]);
  }

  puts(s);

  return 0;
}
