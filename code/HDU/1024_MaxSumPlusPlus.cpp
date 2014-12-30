/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 02 Nov 2014 05:05:29 PM CST
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
#define maxn 1000007

using namespace std;

int dp[2][maxn];
int a[maxn];

inline int ReadInt()
{
  int flag=0;
  char ch=getchar();
  int data=0;
  while (ch<'0' || ch>'9')
  {
    if (ch=='-')flag=1;
    ch=getchar();
  }
  do
  {
    data=data*10+ch-'0';
    ch=getchar();
  }while (ch>='0' && ch<='9');

  if (flag) data=-data;
  return data;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int m,n;

  while (scanf("%d%d",&m,&n)!=EOF)
  {
    for (int i=1;i<=n;i++)
      a[i]=ReadInt();

    memset(dp,0,sizeof dp);
    int cur=1;
    for (int i=0;i<m;i++,cur^=1)
    {
      int MAX=-INF;
      for (int j=i;j<=n;j++)
      {
        dp[cur][j]=max(dp[cur][j-1],MAX)+a[j];
        MAX=max(MAX,dp[cur^1][j]);
      }
    } 

    int MAX=-INF;
    for (int i=m;i<=n;i++)
      MAX=max(MAX,dp[cur^1][i]);

    printf("%d\n",MAX);
  }

  return 0;
}
