/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 13 Sep 2015 11:31:22 AM CST
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

const int maxn = 20007;
const int maxm = 0;

char s[maxn];

int find(char *s,int l,bool ok)
{
  int i=0,j=1,k=0;
  while (i<l && j<l && k<l)
  {
    int d=s[(i+k)%l]-s[(j+k)%l];
    if (d==0) k++;
    else if (d>0)
    {
      j+=k+1;
      k=0;
      if (i==j) j++;
    }
    else
    {
      i+=k+1;
      k=0;
      if (i==j) i++;
    }
  }

  return std::min(i,j);
}

std::string calc(int b, int l)
{
  std::string res = "";
  for (int i = 0; i < l; i++)
  {
    res += s[(i+b) % l];
  }
  return res;
}

unsigned long long ha[maxn<<1];
unsigned long long h[maxn<<1];

unsigned long long has(int p, int l)
{
  return ha[p+l] - ha[p] * h[l];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);
  h[0] = 1;
  for (int i = 1; i < maxn; i++) h[i] = h[i - 1] * 131;

  while (T_T--)
  {
    int l;
    scanf("%d", &l);
    scanf("%s", s);
    int b1 = find(s, l, false);
    std::string s1 = calc(b1, l);
    std::reverse(s, s + l);
    int b2 = find(s,l,true);
    ha[0] = 0;
    h[0] = 1;
    for (int i = 0; i < l*2; i++)
    {
      int j = i + 1;
      ha[j] = ha[j-1] * 131 + (unsigned long long)s[i%l];
    }
    for (int i = b2+1; i < l; i++)
      if (has(i, l) == has(b2, l)) b2 = i;
    std::string s2 = calc(b2, l);
    b1++;
    if (s1 == s2)
    {
      if (b1 == l - b2)
      {
        printf("%d 0", b1);
      }
      else if (b1 <= l - b2) printf("%d 0", b1);
      else printf("%d 1", l - b2);
    }
    else if (s1 > s2) printf("%d 0", b1);
    else printf("%d 1", l - b2);
    puts("");
  }




  return 0;
}
