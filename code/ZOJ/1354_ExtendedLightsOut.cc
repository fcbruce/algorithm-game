/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Jul 2015 08:32:19 AM CST
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
#define maxn 

using namespace std;

int matrix[5][6];

int target[5][6];

int solution[5][6];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

inline void press(int x,int y)
{
  target[x][y]^=1;
  for (int i=0;i<4;i++)
  {
    int tx=x+dx[i],ty=y+dy[i];
    if (0<=tx && tx<5 && 0<=ty && ty<6) target[tx][ty]^=1;
  }
}

bool detect(int status)
{
  for (int i=0;i<6;i++)
    if ((status&(1<<i))!=0) solution[0][i]=1;
    else solution[0][i]=0;
  for (int i=0;i<5;i++) for (int j=0;j<6;j++) target[i][j]=matrix[i][j];
  for (int i=0;i<6;i++) if (solution[0][i]==1) press(0,i);

  for (int i=1;i<5;i++) 
  {
    for (int j=0;j<6;j++)
    {
      solution[i][j]=target[i-1][j];
      if (solution[i][j]) press(i,j);
    }
  }
  for (int i=0;i<6;i++) if (target[4][i]==1) return false;
  for (int i=0;i<5;i++)
  {
    for (int j=0;j<6;j++) 
    {
      if (j>0) putchar(' ');
      printf("%d",solution[i][j]);
    }
    puts("");
  }
  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    printf("PUZZLE #%d\n",++__);

    for (int i=0;i<5;i++) for (int j=0;j<6;j++) scanf("%d",matrix[i]+j);

    for (int i=0;i<(1<<6);i++) 
      if (detect(i))
        break;
  }



  return 0;
}
