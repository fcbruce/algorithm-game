/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Aug 2015 08:27:15 PM CST
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
#define maxn 512

using namespace std;

int n;
double g[maxn][maxn];
bool isroot[maxn];

char buffer[1024];

int cnode;

int col[maxn];
int sons[maxn];

vector<int> save[maxn];

int fir[maxn];
int u[maxn], v[maxn], nex[maxn];
int e_max;

inline void add_edge(int s, int t)
{
  int e = e_max++;
  u[e] = s; v[e] = t;
  nex[e] = fir[u[e]]; fir[u[e]] = e;
}

void scan(int s, char *&p)
{
  save[s].clear();
  int cnt = 0;

  while ((*p) != '\0')
  {
    if  (isspace(*p)) p++;
    else if (islower(*p)) 
    {
      cnt++;
      col[cnode] = (*p) - 'a';
      add_edge(s, cnode);
      cnode++;
      p++;
    }
    else if ((*p) == '(')
    {
      cnt++;
      p++;
      col[cnode] = -1;
      add_edge(s, cnode);
      scan(cnode++, p);
    }
    else if ((*p) == ')')
    {
      sons[s] = cnt;
      p++;
      return ;
    }
    else
    {
      cnt++;
      bool f = false;
      if ((*p) == '-')
      {
        f = true;
        p++;
      }
      int data = 0;
      while (isdigit(*p)) 
      {
        data *= 10;
        data += (*p) - '0';
        p++;
      }
      if (f) data = -data;
      save[s].push_back(data);
    }
  }
}

void dfs(int s, double p, int r)
{
  p /= sons[s];
  for (int e = fir[s]; ~e; e = nex[e])
  {
    if (col[v[e]] != -1)
      g[r][col[v[e]]] -= p;
    else dfs(v[e], p, r);
  }

  for (size_t i = 0; i < save[s].size(); i++) g[r][n] += p * save[s][i];
}

void analyse(char *p)
{
  e_max = 0;
  memset(fir, -1, sizeof fir);
  int r = (*p) - 'a';
  cnode = 0;
  col[cnode] = -1;
  sons[cnode] = 1;
  cnode++;
  g[r][r] = 1;
  while ((*p) != '(') p++;
  p++;
  scan(0, p);
  dfs(0, 1, r);
}

void gauss(double a[][maxn], int n)
{
  for (int i = 0; i < n; i++)
  {
    int r = i;
    for (int j = i + 1; j < n; j++) if (fabs(a[r][i]) < fabs(a[j][i])) r = j;
    if (r != i) for (int j = i; j <= n; j++) swap(a[r][j], a[i][j]);

    if (fabs(g[i][i]) < eps) continue;
    
    for (int k = i + 1; k < n; k++)
    {
      double f = a[k][i] / a[i][i];
      for (int j = i; j <= n; j++) a[k][j] -= f * a[i][j];
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    isroot[i] = true;

    if (fabs(a[i][i]) < eps) 
    {
      isroot[i] = false;
      continue ;
    }

    for (int j = i + 1; j < n; j++) if (fabs(a[i][j]) > eps) 
    {
      if (!isroot[j])
      {
        isroot[i] = false;
        break ;
      }
      a[i][n] -= a[i][j] * a[j][n];
    }

    if (isroot[i]) a[i][n] /= a[i][i];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __ = 0;

  while (scanf("%d", &n) == 1 && n > 0)
  {
    memset(g, 0 ,sizeof g);
    gets(buffer);
    for (int i = 0; i < n; i++)
    {
      gets(buffer);
      analyse(buffer);
    }

    gauss(g, n);

    printf("Game %d\n", ++__);
    for (int i = 0; i < n; i++) 
      if (isroot[i]) printf("Expected score for %c = %.3f\n", i + 'a', g[i][n]);
      else printf("Expected score for %c undefined\n", i + 'a');
    puts("");
  }



  return 0;
}
