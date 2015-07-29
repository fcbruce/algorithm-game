/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 28 Jul 2015 09:24:04 PM CST
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
#define maxn 500007

using namespace std;

int cnt[128],c[maxn];
char T[maxn],P[maxn];

inline bool same(int *a,int *b,int n) 
{
  for (int i=0;i<n;i++) if (a[i]!=b[i]) return false;
  return true;
}

vector<int> res;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s%s",T,P)==2)
  {
    int l1=strlen(T);
    int l2=strlen(P);

    res.clear();

    memset(cnt,0,sizeof cnt);
    memset(c,0,sizeof c);

    for (int i=0;i<l2;i++) cnt[P[i]]++;
    for (int i=0;i<128;i++) c[cnt[i]]--;

    int non=0;
    for (int i=1;i<=l2;i++) if (c[i]!=0) non++;

    memset(cnt,0,sizeof cnt);

    for (int i=0;i<l1;i++)
    {
      char ch=T[i];
      if (c[cnt[ch]] == 0) non++;
      else if (c[cnt[ch]] == 1) non--;
      c[cnt[ch]]--;
      cnt[ch]++;
      if (c[cnt[ch]] == 0) non++;
      else if (c[cnt[ch]] == -1) non--;
      c[cnt[ch]]++;

      if (i>=l2)
      {
        ch=T[i-l2];
        if (c[cnt[ch]]==0) non++;
        else if (c[cnt[ch]]==1) non--;
        c[cnt[ch]]--;
        cnt[ch]--;
        if (c[cnt[ch]]==0) non++;
        else if (c[cnt[ch]]==-1) non--;
        c[cnt[ch]]++;
      }

      if (non==0) res.push_back(i-l2+1);

    }


    if (res.empty()) puts("No");
    else
    {
      puts("Yes");

      for (size_t i=0;i<res.size();i++)
      {
        if (i!=0) putchar(' ');
        printf("%d",res[i]);
      }
      puts("");
    }

  }



  return 0;
}
