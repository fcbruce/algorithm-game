/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 06 Aug 2015 06:44:17 PM CST
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
#define maxn 1<<24

using namespace std;

struct point
{
  int x,y;
  void read()
  {
    scanf("%d%d",&x,&y);
  }
  int dis(const point &rhs)
  {
    return sqr(x-rhs.x)+sqr(y-rhs.y);
  }
}p[24],o;

int dis[24][24];
int len[24];

int dp[maxn];
pair<int,int> choice[maxn];
int pre[maxn];

int n;

int dfs(int s)
{
  if (s==0) return 0;
  if (dp[s]!=INF) return dp[s];

  for (int i=0;i<n;i++) if ((s&(1<<i))!=0)
  {
    int nex=s&(~(1<<i));
    int res=dfs(nex)+len[i];
    if (dp[s]>res)
    {
      dp[s]=res;
      pre[s]=nex;
      choice[s]={i+1,-1};
    }
    for (int j=i+1;j<n;j++) if ((s&(1<<j))!=0)
    {
      int nex=s&(~(1<<i))&(~(1<<j));
      int res=dfs(nex)+dis[i][j];
      if (dp[s]>res)
      {
        dp[s]=res;
        pre[s]=nex;
        choice[s]={i+1,j+1};
      }
    }
    break;
  }

  return dp[s];
}

void prt(int s)
{
  if (s==0)
  {
    printf("0");
    return ;
  }
  prt(pre[s]);
  printf(" %d",choice[s].first);
  if (choice[s].second>0) printf(" %d",choice[s].second);
  printf(" 0");
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  memset(dp,0x3f,sizeof dp);

  o.read();

  scanf("%d",&n);

  for (int i=0;i<n;i++)
  {
    p[i].read();
    len[i]=o.dis(p[i])*2;
  }

  for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) 
    dis[i][j]=p[i].dis(p[j])+o.dis(p[i])+o.dis(p[j]);

  printf("%d\n",dfs((1<<n)-1));

  prt((1<<n)-1);

  puts("");


  return 0;
}
