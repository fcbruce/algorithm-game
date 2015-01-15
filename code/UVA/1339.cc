/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 10:49:30 PM CST
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

char s1[maxn],s2[maxn];
int a1[maxn],a2[maxn];
int cnt1[maxn],cnt2[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s%s",s1,s2)==2)
  {
    int l=strlen(s1);
    memset(cnt1,0,sizeof cnt1);
    memset(cnt2,0,sizeof cnt2);
    for (int i=0;i<l;i++)
    {
      cnt1[s1[i]-'A']++;
      cnt2[s2[i]-'A']++;
    }

    sort(cnt1,cnt1+maxn);
    sort(cnt2,cnt2+maxn);

    if ([&]()
        {
          for (int i=0;i<maxn;i++) if (cnt1[i]!=cnt2[i]) return false;
          return true;
        }())
      puts("YES");
    else
      puts("NO");
  }


  return 0;
}
