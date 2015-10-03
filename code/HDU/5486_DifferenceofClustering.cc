/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Oct 2015 07:48:31 PM CST
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

const int maxn = 1000007;
const int maxm = 0;

std::map<int, int> left, right;
std::set<int> visleft, visright;

std::pair<int, int> relation[maxn];

std::map<int, std::vector<int> > edge;

bool okright(int s)
{
  auto &e = edge[s];
  for (auto v : e) if (right[v] != 1) return false;
  return true;
}

bool okleft(int s)
{
  auto &e = edge[s];
  for (auto v : e) if (left[v] != 1) return false;
  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &relation[i].first, &relation[i].second);

    std::sort(relation, relation + n);
    n = std::unique(relation, relation + n) - relation;

    left.clear();
    right.clear();

    edge.clear();
    for (int i = 0; i < n; i++) 
    {
      left[relation[i].first]++;
      right[relation[i].second]++;
      edge[relation[i].first].push_back(relation[i].second);
    }

    int splits = 0, merges = 0, onetoones = 0;
    visleft.clear();
    visright.clear();

    for (int i = 0; i < n; i++) 
    {
      if (left[relation[i].first] == 1 && right[relation[i].second] == 1) onetoones++;
      else if (left[relation[i].first] > 1 && visleft.count(relation[i].first) == 0)
      {
        if (okright(relation[i].first))
          splits++;
        visleft.insert(relation[i].first);
      }
    }

    edge.clear();
    for (int i = 0; i < n; i++) edge[relation[i].second].push_back(relation[i].first);

    for (int i = 0; i < n; i++)
    {
      if (right[relation[i].second] > 1 && visright.count(relation[i].second) == 0)
      {
        if (okleft(relation[i].second))
          merges++;
        visright.insert(relation[i].second);
      }
    }

    printf("Case #%d: %d %d %d\n", ++__, splits, merges, onetoones);

  }




  return 0;
}
