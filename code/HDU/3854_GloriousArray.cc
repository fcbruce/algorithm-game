/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 16 Aug 2015 02:25:50 PM CST
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
#define maxn 100007

using namespace std;

int col[maxn];
int a[maxn];

int s[2],cnt[2][maxn];
int id[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", col + i);

    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);
    int idx = 0;
    long long res = 0;

    for (int i = 1; i <= n; i++)
    {
      if (a[i] < k || i > 1 && a[i - 1] < k) idx++;
      id[i]=idx;
      s[col[i]]++;
      cnt[col[i]][idx]++;
      res += s[col[i] ^ 1] - cnt[col[i] ^ 1][idx];
    }

    while (m--)
    {
      int cmd;
      scanf("%d", &cmd);
      if (cmd == 1) printf(lld "\n", res);
      else
      {
        int p;
        scanf("%d", &p);
        res -= s[col[p] ^ 1] - cnt[col[p] ^ 1][id[p]];
        s[col[p]]--;
        cnt[col[p]][id[p]]--;
        col[p] ^= 1;
        s[col[p]]++;
        cnt[col[p]][id[p]]++;
        res += s[col[p] ^ 1] - cnt[col[p] ^ 1][id[p]];
      }
    }
  }




  return 0;
}
