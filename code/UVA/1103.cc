/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 02 Mar 2015 03:11:14 PM CST
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
#define maxn 233

using namespace std;

int n,m;

char buff[233];
bool G[maxn][maxn];
bool g[maxn][maxn];

vector<char> mess;

char ch[]=" WAKJSD";

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void read()
{
  for (int i=0;i<n;i++)
  {
    scanf("%s",buff);
    for (int j=0;j<m;j++)
    {
      int x;
      if (isdigit(buff[j])) x=buff[j]-'0';
      else x=buff[j]-'a'+10;
      for (int k=0;k<4;k++) G[i][j*4+k]=(x&(1<<(3-k)))>0;
    }
  }

  m<<=2;
}

inline bool inmapG(int i,int j)
{
  return 0<=i && i<n && 0<=j && j<m;
}

inline bool inmapg(int i,int j)
{
  return 0<=i && i<n+2 && 0<=j && j<m+2;
}

void dfs(int x,int y)
{
  g[x+1][y+1]=G[x][y];

  G[x][y]=false;
  
  for (int i=0;i<4;i++) 
  {
    int tx=x+dx[i],ty=y+dy[i];
    if (inmapG(tx,ty) && G[tx][ty]) dfs(tx,ty);
  }
}

void Dfs(int x,int y)
{
  g[x][y]=true;
  for (int i=0;i<4;i++)
  {
    int tx=x+dx[i],ty=y+dy[i];
    if (inmapg(tx,ty) && !g[tx][ty]) Dfs(tx,ty);
  }
}

inline int count()
{
  int cnt=0;

  for (int i=0;i<n+2;i++) for (int j=0;j<m+2;j++)
  {
    if (!g[i][j])
    {
      cnt++;
      Dfs(i,j);
    }
  }

  return cnt;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d%d",&n,&m),n!=0 && m!=0)
  {
    read();

    mess.clear();
    for (int i=0;i<n;i++) for (int j=0;j<m;j++)
    {
      if (G[i][j]) 
      {
        memset(g,0,sizeof g);

        dfs(i,j);

        int k=count();

        mess.push_back(ch[k]);
      }
    }

    sort(mess.begin(),mess.end());

    printf("Case %d: ",++__);
    for (auto e : mess) putchar(e);
    puts("");
  }

  return 0;
}
