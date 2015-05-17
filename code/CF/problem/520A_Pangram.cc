/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 07 Apr 2015 08:12:18 PM CST
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
bool vis[26];

inline bool ok()
{
  for (int i=0;i<26;i++) if (!vis[i]) return false;
  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn n;
  scanf("%d",&n);

  scanf("%s",s);

  memset(vis,0,sizeof vis);
  
  for (int i=0;i<n;i++) vis[tolower(s[i])-'a']=true;

  puts(ok()?"YES":"NO");

  return 0;
}
