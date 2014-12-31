/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 30 Dec 2014 11:50:47 PM CST
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

#define maxm 1111
#define maxn 555

using namespace std;

int w[maxn],b[maxm];

bool vis[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  scanf("%d%d",&n,&m);

  for (int i=0;i<n;i++) scanf("%d",w+i);
  for (int i=0;i<m;i++) scanf("%d",b+i);

  int total=0;
  
  for (int i=0;i<m;i++)
  {
    memset(vis,0,sizeof vis);
    for (int j=i-1;j>=0 && b[j]!=b[i];j--)
    {
      if (!vis[b[j]])
      {
        vis[b[j]]=true;
        total+=w[b[j]-1];
      }
    }
  }

  printf("%d\n",total);


  return 0;
}
