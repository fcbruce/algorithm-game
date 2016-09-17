/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 17 Sep 2016 14:11:23
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
const int maxm = 26;

int q[maxn];
int found[maxn];
char buffer[maxn];

struct ACauto  
{  
  int ch[maxn][maxm];  
  int val[maxn];  
  int nex[maxn];  
  int last[maxn];  
  int cnt;  
  int sz;  
  
  ACauto()  
  {  
    sz = 1;  
    val[0] = 0;  
    memset(ch[0], 0, sizeof ch[0]);  
  }  
  
  void clear()  
  {  
    sz = 1;  
    val[0] = 0;  
    memset(ch[0], 0, sizeof ch[0]);  
  }  
  
  int idx(const char ch)  
  {  
    return ch - 'a';  
  }  
  
  void insert(const char *s,int v = 1)  
  {  
    int u = 0;  
    for (int i = 0; s[i] != '\0'; i++)  
    {  
      int c = idx(s[i]);  
      if (ch[u][c] == 0)  
      {  
        val[sz] = 0;  
        memset(ch[sz], 0, sizeof ch[sz]);  
        ch[u][c] = sz++;  
      }  
      u = ch[u][c];  
    }  
    val[u] = v;  
  }  
  
  void get_fail()  
  {  
    int f = 0, r = -1;  
    nex[0] = 0;  
    last[0] = 0;  
    for (int c = 0; c < maxm; c++)  
    {  
      int u = ch[0][c];  
      if (u != 0)  
      {  
        nex[u] = 0;  
        q[++r] = u;  
        last[u] = 0;  
      }  
    }  
  
    while (f <= r)  
    {  
      int x = q[f++];  
      for (int c = 0; c < maxm; c++)  
      {  
        int u = ch[x][c];  
        if (u == 0) continue;  
        q[++r] = u;  
        int j = nex[x];  
        while (j > 0 && ch[j][c] == 0) j = nex[j];  
        nex[u] = ch[j][c];  
        last[u] = val[nex[u]] > 0 ? nex[u] : last[nex[u]];  
      }  
    }  
  }  
  
  void calc(int j, int i)  
  {  
    if (j != 0)  
    {  
      cnt++;  
      found[i] = std::max(found[i], val[j]);  
      calc(last[j], i);  
    }  
  }  
  
  void find(const char *T)  
  {  
    cnt = 0;  
    memset(found, 0, sizeof found);  
  
    for (int i = 0, j = 0; T[i] != '\0'; i++)  
    {  
      int c = idx(T[i]);  
      while (j > 0 && ch[j][c] == 0) j=nex[j];  
      j = ch[j][c];  
      if (val[j] != 0)  
        calc(j, i);  
      else if (last[j] != 0)  
        calc(last[j], i);  
    }  
  }  
}acauto;  

char T[maxn], T_[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    acauto.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      scanf("%s", buffer);
      int len = strlen(buffer);
      acauto.insert(buffer, len);
    }

    gets(buffer);
    gets(T);

    int len = strlen(T);
    for (int i = 0; T[i]; i++)
      T_[i] = tolower(T[i]);

    T_[len] = '\0';

    acauto.get_fail();
    acauto.find(T_);

    int left = len;
    for (int i = len - 1; i >= 0; i--)
    {
      left = std::min(left, i - found[i]);
      if (i > left) T[i] = '*';
    }

    puts(T);
  }




  return 0;
}
