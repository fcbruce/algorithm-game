/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 13 Sep 2015 09:44:54 AM CST
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

const int maxm = 0;
const int maxn = 150007;

using namespace std;

char name[maxn][233];

struct people
{
  int v,id;
  void read(int i)
  {
    id = i;
    scanf("%s",name[i]);
    scanf("%d", &v);
  }
  bool operator < (const people &rhs) const
  {
    if (v== rhs.v) return id>rhs.id;
    return v < rhs.v;
  }
}p[maxn];

priority_queue<people> q;

int kth[maxn];

int l[maxn];


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n,m,Q;
    scanf("%d%d%d",&n,&m,&Q);
    for (int i=0;i<n;i++) p[i].read(i);
    while (!q.empty()) q.pop();
    int k = 0;
    memset(l, 0, sizeof l);
    for (int i=0; i<m;i++)
    {
      int t,p;
      scanf("%d%d",&t,&p);
      l[t] += p;
    }
    l[n] = n;
    for (int i=1; i<=n;i++)
    {
      q.push(p[i-1]);
      while (l[i] > 0 && !q.empty())
      {
        people tmp = q.top();
        q.pop();
        kth[k++] = tmp.id;
        l[i]--;
      }
    }
    for (int i = 0; i<Q;i++)
    {
      int x;
      scanf("%d",&x);
      x--;
      if (i>0) putchar(' ');
      printf("%s",name[kth[x]]);
    }
    puts("");
  }




  return 0;
}
