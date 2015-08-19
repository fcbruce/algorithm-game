/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 19 Aug 2015 04:20:30 PM CST
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

inline int pow_mod(long long x, int n, int mod)
{
  long long res = 1;
  while (n != 0)
  {
    if (n & 1)
    {
      res *= x;
      res %= mod;
    }
    x *= x;
    x %= mod;
    n >>= 1;
  }
  return (int)res;
}

long long A[2][2];

inline void multi(long long lhs[2][2], long long rhs[2][2], int mod)
{
  long long tmp[2][2] = {0, 0, 0, 0};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        tmp[i][j] = (lhs[i][k] * rhs[k][j] % mod + tmp[i][j]) % mod;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      lhs[i][j] = tmp[i][j];
}

inline void pow_mod(long long A[2][2], int y2, int z2, int mod)
{
  long long res[2][2] = {{1, 0}, {0, 1}};
  long long tmp[2][2];
  memcpy(tmp, A, sizeof tmp);
  
  while (z2 != 0)
  {
    if (z2 & 1) multi(res, tmp, mod);
    multi(tmp, tmp, mod);
    z2 >>= 1;
  }

  while (y2--) multi(A, A, mod);

  multi(A, res, mod);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int x1, y1, z1, y2, z2, p;

  while (scanf("%d%d%d", &x1, &y1, &z1) == 3)
  {
    if (x1 == -1 && y1 == -1 && z1 == -1) break ;
    scanf("%d%d", &y2, &z2);
    scanf("%d", &p);
    int q = pow_mod(x1, y1, p) + z1;
    q %= p;
    A[0][0] = q - 1; A[0][1] = q;
    A[1][0] = 1; A[1][1] = 0;
    pow_mod(A, y2, z2, p);
    printf(lld "\n", A[1][0]);
  }



  return 0;
}
