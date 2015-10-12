/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Oct 2015 08:36:13 PM CST
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
#ifdef _WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0);
const double eps = 1e-10;

typedef long long LL;
typedef int itn;

const int maxn = 0;
const int maxm = 0;

int stick[64];
bool vis[64];

int n;

inline int readint()
{
  int data = 0;
  char ch = getchar();

  while (!isdigit(ch)) ch = getchar();

  do
  {
    data = data * 10 + ch - '0';
    ch = getchar();
  }while (isdigit(ch));

  return data;
}

bool dfs(int l, int b, int d, int length)
{
  if (l == 0)
  {
    if (d == 0) return true;
    l = length;
    b = 0;
  }
  if (d == 0) return l == 0;
  if (b == n) return false;
  for (int i = b; i < n; i++) if (l >= stick[i] && !vis[i])
  {
    vis[i] = true;
    if (dfs(l - stick[i], i + 1, d - 1, length)) return true;
    vis[i] =false;

    if (l == stick[i]) return false;
    
    if (l == length) return false;
  }

  return false;

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE


  while (n = readint())
  {

    int total = 0;
    int length = 0;
    for (int i = 0 ; i < n; i++)
    {
      stick[i] = readint();
      total += stick[i];
      length = std::max(length, stick[i]);
    }

    std::sort(stick, stick + n);
    std::reverse(stick, stick + n);

    for (; length < total; length++) if (total % length == 0)
    {
      memset(vis, 0, sizeof vis);
      if (dfs(length ,0,  n, length)) break;
    }


    printf("%d\n", length);



  }




  return 0;
}
