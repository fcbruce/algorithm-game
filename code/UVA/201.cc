/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 11 Feb 2015 09:44:48 PM CST
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
#define maxn 10

using namespace std;

bool H[maxn][maxn],V[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,__=0;

  while (scanf("%d",&n)==1)
  {
    scanf("%d",&m);

    memset(H,0,sizeof H);
    memset(V,0,sizeof V);

    for (int i=0;i<m;i++)
    {
      char op;
      int x,y;
      scanf(" %c %d %d",&op,&x,&y);
      if (op=='H') H[x][y]=true;
      else V[y][x]=true;
    }

    if (__>0)
    {
      puts("");
      puts("**********************************");
      puts("");
    }

    printf("Problem #%d\n\n",++__);

    bool output=false;
    for (int l=1;l<n;l++)
    {
      int cnt=0;
      for (int i=1;i<=n-l;i++) for (int j=1;j<=n-l;j++)
      {
        bool ok=true;
        for (int k=0;k<l;k++) if (V[i+k][j] && V[i+k][j+l] && H[i][j+k] && H[i+l][j+k]) ;
        else 
        {
          ok=false;
          break;
        }

        if (ok) cnt++;
      }
      if (cnt>0)
      {
        printf("%d square (s) of size %d\n",cnt,l);
        output=true;
      }
    }
    if (!output) puts("No completed squares can be found.");
  }

  return 0;
}
