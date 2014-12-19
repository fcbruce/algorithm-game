/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 25 Oct 2014 07:10:43 PM CST
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
#define maxn 1007

using namespace std;

int trans[maxn][maxn][3];
char matrix[maxn][maxn];
int n,m;
int ql[maxn],qr[maxn],fl,rl,fr,rr;
int h[maxn];
int l[maxn],r[maxn];

inline void init(int x,int y,char ch)
{
  switch (ch)
  {
    case 'a':
      trans[x][y][0]=1;
      break;
    case 'b':
      trans[x][y][1]=1;
      break;
    case 'c':
      trans[x][y][2]=1;
      break;
    case 'w':
      trans[x][y][0]=trans[x][y][1]=1;
      break;
    case 'x':
      trans[x][y][1]=trans[x][y][2]=1;
      break;
    case 'y':
      trans[x][y][0]=trans[x][y][2]=1;
      break;
    case 'z':
      trans[x][y][0]=trans[x][y][1]=trans[x][y][2]=1;
      break;
  }
}

int solve(int k)
{
  int MAX=0;
  memset(h,0,sizeof h);
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<m;j++)
    {
      if (trans[i][j][k]==1) h[j]++;
      else h[j]=0;
    }

    fl=fr=0;rl=rr=-1;
    for (int j=0;j<m;j++)
    {
      while (fl<=rl && h[ql[rl]]>=h[j]) rl--;
      if (fl<=rl) l[j]=ql[rl]+1;
      else l[j]=0;
      ql[++rl]=j;

      while (fr<=rr && h[qr[rr]]>=h[m-j-1]) rr--;
      if (fr<=rr) r[m-j-1]=qr[rr];
      else r[m-j-1]=m;
      qr[++rr]=m-j-1;
    }

    for (int j=0;j<m;j++)
      MAX=max(MAX,h[j]*(r[j]-l[j]));
  }

  return MAX;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&m)==2)
  {
    for (int i=0;i<n;i++)
      scanf("%s",matrix[i]);

    memset(trans,0,sizeof trans);
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        init(i,j,matrix[i][j]);

    int MAX=0;
    for (int i=0;i<3;i++)
      MAX=max(MAX,solve(i));

    printf("%d\n",MAX);
  }


  return 0;
}
