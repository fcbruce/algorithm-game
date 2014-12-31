/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 30 Dec 2014 11:10:00 PM CST
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
#define maxn 303

using namespace std;

int G[maxn][maxn];

int a[maxn];

int s[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=0;i<n;i++) scanf("%d",a+i);

  for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%1d",&G[i][j]);

  for (int i=0;i<n;i++) G[i][i]=1;

  for (int k=0;k<n;k++)
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        G[i][j]|=G[i][k]*G[k][j];

  int cnt;
  for (int i=0;i<n;i++)
  {
    cnt=0;
    for (int j=0;j<n;j++)
    {
      
      if (G[i][j]>0) s[cnt++]=a[j];
      
    }
    sort(s,s+cnt);
    cnt=0;
    for (int j=0;j<n;j++)
      if (G[i][j]>0) a[j]=s[cnt++];
  }

  for (int i=0;i<n;i++) printf("%d ",a[i]);


  return 0;
}
