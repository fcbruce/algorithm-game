/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 12 Feb 2015 03:43:17 PM CST
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

char G[10][10];
vector<pair<int,int> > v;

inline bool in(int x)
{
  return 0<x && x<9;
}

bool ok(int x,int y,char ch)
{
  for (int i=-1;i<=1;i++) for (int j=-1;j<=1;j++) if (i!=0 || j!=0)
  {
    itn cnt=0;
    int tx=x+i,ty=y+j;
    while (in(tx) && in(ty) && ch!=G[tx][ty] && G[tx][ty]!='-')
    {
      cnt++;
      tx+=i;
      ty+=j;
    }
    if (in(tx) && in(ty) && G[tx][ty]==ch && cnt>0) return true; 
  }
  return false;
}

void cando(int cur)
{
  v.clear();
  for (int i=1;i<=8;i++) for (int j=1;j<=8;j++) if (G[i][j]=='-')
    if (ok(i,j,cur>0?'W':'B')) v.push_back({i,j});
}

void put(int cur,int x,int y)
{
  char ch=cur>0?'W':'B';
  G[x][y]=ch;
  for (int i=-1;i<=1;i++) for (int j=-1;j<=1;j++) if (i!=0 || j!=0)
  {
    itn cnt=0;
    int tx=x+i,ty=y+j;
    while (in(tx) && in(ty) && G[tx][ty]!='-' && G[tx][ty]!=ch)
    {
      cnt++;
      tx+=i;
      ty+=j;
    }
    if (in(tx) && in(ty) && G[tx][ty]==ch && cnt>0)
    {
      while (tx!=x || ty!=y) 
      {
        G[tx][ty]=ch;
        tx-=i;
        ty-=j;
      }
    }
  }
  
  int cw=0,cb=0;
  for (int i=1;i<=8;i++) for (int j=1;j<=8;j++)
  {
    if (G[i][j]=='W') ++cw;
    else if (G[i][j]=='B') ++cb;
  }
  printf("Black - %2d White - %2d\n",cb,cw);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    for (int i=1;i<=8;i++) scanf("%s",G[i]+1);
    
    char ch;
    scanf(" %c",&ch);
    int cur=ch=='W'?1:0;

    while (scanf(" %c",&ch),ch!='Q')
    {
      cando(cur);

      if (ch=='M')
      {
        if (v.size()==0) cur^=1;

        int x,y;
        scanf("%1d%1d",&x,&y);

        put(cur,x,y);
        cur^=1;
      }
      else
      {
        if (v.size()==0) puts("No legal move.");
        else
        {
          bool fir=true;
          for (auto i : v)
          {
            if (!fir) putchar(' ');
            fir=false;
            printf("(%d,%d)",i.first,i.second);
          }
          putchar('\n');
        }
      }
    }
    
    for (int i=1;i<=8;i++) puts(G[i]+1);

    if (T_T>0) puts("");
  }

  return 0;
}
