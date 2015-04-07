/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 06 Apr 2015 06:46:08 PM CST
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

#define maxm 10007
#define maxn 107

using namespace std;

vector<int> v[maxn];

char g[maxn][maxm];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  scanf("%d%d",&n,&m);

  bool ok=true;

  for (int i=0;i<n;i++)
  {
    scanf("%s",g[i]);
    for (int j=0;j<m;j++)
      if (g[i][j]=='1') v[i].push_back(j);
    if (v[i].size()==0) ok=false;
  }

  if (!ok)
  {
    puts("-1");
    return 0;
  }


  int res=INF;
  for (int i=0;i<m;i++)
  {
    int cnt=0;
    for (int j=0;j<n;j++)
    {
      int a=lower_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
      int x,y;
      if (a==0)
      {
        x=v[j][a]-i;
        y=m-v[j][v[j].size()-1]+i;
      }
      else if (a==v[j].size())
      {
        y=i-v[j][a-1];
        x=m-i+v[j][0];
      }
      else
      {
        x=v[j][a]-i;
        y=i-v[j][a-1];
      }

      cnt+=min(x,y);

    }
    res=min(res,cnt);
  }

  printf("%d\n",res);

  return 0;
}
