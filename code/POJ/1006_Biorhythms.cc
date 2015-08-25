/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 25 Aug 2015 09:09:40 AM CST
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

int m[] = {23, 28, 33};
int a[3];
int d;

int gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  int d = gcd(b, a % b, y, x);
  y -= x * a / b;
  return d;
}

int CRT(int a[], int m[], int n)
{
  int M = 1;
  int res = 0;
  for (int i = 0; i < n; i++) M *= m[i];
  for (int i = 0; i < n; i++)
  {
    int x, y;
    int mi = M / m[i];
    gcd(mi, m[i], x, y);
    res += a[i] * mi * x % M;
    res %= M;
  }
  return res;
}

bool read()
{
  for (int i = 0; i < 3; i++) scanf("%d", a + i);
  scanf("%d", &d);
  return d != -1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __ = 0;

  while (read())
  {
    int res = CRT(a, m, 3) - d;
    res %= 21252; res += 21252; res %= 21252;
    if (res == 0) res += 21252;
    printf("Case %d: the next triple peak occurs in %d days.\n", ++__, res);
  }



  return 0;
}
