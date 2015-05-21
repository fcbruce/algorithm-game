/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 20 May 2015 07:50:41 PM CST
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

char c[]="A23456789XJQKA";

struct Card
{
  int v;
  char type;
  void set(char *s)
  {
    type=s[0];
    for (int i=0;c[i];i++) if (c[i]==s[1])
    {
      v=i;
      break;
    }
  }
  bool operator < (const Card &rhs) const
  {
    return v<rhs.v;
  }
  void prt()
  {
    printf("%c %d\n",type,v);
  }
}card[5];

bool flush()
{
  for (int i=1;i<5;i++) if (card[i].type!=card[0].type) return false;
  return true;
}

bool straight()
{
  if (card[0].v==0)
  {
    bool ok=true;
    for (int i=1;i<5;i++) if (card[i].v!=8+i)
    {
      ok=false;
      break;
    }
    if (ok) return true;
  }
  
  for (int i=1;i<4;i++) if (card[i].v!=i+card[0].v) return false;
  return true;
}

bool sf()
{
  return flush() && straight();
}

bool fk()
{
  return card[0].v==card[3].v || card[1].v==card[4].v;
}

bool fh()
{
  return card[0].v==card[2].v && card[3].v==card[4].v || card[0].v==card[1].v && card[2].v==card[4].v;
}

bool tk()
{
  return card[0].v==card[2].v || card[2].v==card[4].v;
}

bool tp()
{
  return card[0].v==card[1].v && card[2].v==card[3].v || card[0].v==card[1].v && card[3].v==card[4].v || card[1].v==card[2].v && card[3].v==card[4].v;
}

bool op()
{
  for (int i=0;i<3;i++) if (card[i].v==card[i+1].v) return true;
  return false;
}

int score()
{
  if (sf()) return 1000;
  if (fk()) return 750;
  if (fh()) return 500;
  if (flush()) return 350;
  if (straight()) return 250;
  if (tk()) return 200;
  if (tp()) return 100;
  if (op()) return 50;
  return 0;
}

char buff[233];


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    for (int i=0;i<5;i++)
    {
      scanf("%s",buff);
      card[i].set(buff);
    }

    sort(card,card+5);

    printf("%d\n",score());
  }



  return 0;
}
