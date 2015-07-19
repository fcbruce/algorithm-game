/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 17 Jul 2015 07:12:35 PM CST
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

string s[] = {"A", "C", "G", "AC", "AG", "CG", "ACG"};
int cnt[] = {1, 1, 1, 2, 2, 2, 3};

map<string,int> MAP;

int vis[7];

char buff[1024];

inline bool sim(int a, int b)
{
  for (auto i : s[a]) for (auto j : s[b]) if (i == j) return true;
  return false;
}

bool dfs(int s, int far)
{
  vis[s]--;
  bool ok = true;
  for (int i = 0; i < 7 && ok; i++) ok = vis[i] == 0;
  if (ok && sim(s, far)) return true;

  for (int i = 0; i < 7; i++)
    if (vis[i] != 0 && sim(s, i) && dfs(i, far)) return true;

  vis[s]++;
  return false;
}

inline bool judge()
{
  for (int i = 0; i < 7; i++) if (vis[i] != 0) return dfs(i, i);
  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d", &n) == 1)
  {
    MAP.clear();
    for (int i = 0; i < n; i++)
    {
      scanf("%s", buff);
      scanf("%s", buff);
      int l = strlen(buff);
      sort(buff, buff + l);
      MAP[string(buff)]++;
    }

    for (int i = 0; i < 7; i++)
      vis[i] = min(MAP[string(s[i])], cnt[i]);

    puts(judge() ? "Yes" : "No");

  }



  return 0;
}
