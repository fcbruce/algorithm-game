/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 09:59:50 AM CST
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

char G[9][9];
char cmd[]="ABRL";

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (fgets(G[0],9,stdin),strcmp(G[0],"Z\n")!=0)
  {
    for (int i=1;i<5;i++) fgets(G[i],9,stdin);

    int bx,by;

    for (int i=0;i<5;i++)
      for (int j=0;j<5;j++)
        if (G[i][j]==' ')
        {
          bx=i;
          by=j;
          break;
        }

    char op;
    bool ok=true;
    while ((op=getchar())!='0')
    {
      int tx=bx,ty=by;
      [](char op,int &tx,int &ty){for (int i=0;i<4;i++) if (op==cmd[i]) {tx+=dx[i];ty+=dy[i];break;}}(op,tx,ty);
      auto judge = [](int x){return x>=0 && x<5;};
      if (ok&=(judge(tx) && judge(ty)))
        swap(G[bx][by],G[tx][ty]);
      bx=tx;by=ty;
    }
    getchar();

    if (__>0) putchar('\n');
    printf("Puzzle #%d:\n",++__);

    if (ok)
    {
      for (int i=0;i<5;i++)
      {
        putchar(G[i][0]);
        for (int j=1;j<5;j++) printf(" %c",G[i][j]);
        putchar('\n');
      }
    }
    else puts("This puzzle has no final configuration.");
  }


  return 0;
}
