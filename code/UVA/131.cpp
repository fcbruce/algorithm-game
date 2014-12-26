/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 25 Dec 2014 08:51:04 PM CST
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

char Hand[5][5],Deck[5][5],temp[5][5];
char res[9][30]={"straight-flush","four-of-a-kind",
                  "full-house","flush","straight",
                  "three-of-a-kind","two-pairs",
                  "one-pair","highest-card"};

char point[]="A23456789TJQKA";

int a[5],b[5];

int id;

inline int ctoi1(char c)
{
  for (int i=0;i<13;i++) if (c==point[i]) return i;
}

inline int ctoi2(char c)
{
  for (int i=1;i<14;i++) if (c==point[i]) return i;
}

bool F()
{
  for (int i=1;i<5;i++) if (temp[i][1]!=temp[0][1]) return false;
  return true;
}

bool Sa()
{
  for (int i=1;i<5;i++) if (a[i-1]+1!=a[i]) return false;
  return true;
}

bool Sb()
{
  for (int i=1;i<5;i++) if (b[i-1]+1!=b[i]) return false;
  return true;
}

inline bool S()
{
  return Sa() || Sb();
}

bool SF()
{
  return S() && F();
}

bool FOAK()
{
  return a[0]==a[3] || a[1]==a[4];
}

bool FH()
{
  return (a[0]==a[2] && a[3]==a[4]) || (a[0]==a[1] && a[2]==a[4]);
}

bool TOAK()
{
  return a[0]==a[2] || a[1]==a[3] || a[2]==a[4];
}

bool TP()
{
  int cnt=0;
  for (int i=1;i<5;i++) if (a[i]==a[i-1]) {cnt++;i++;}
  return cnt>=2;
}

bool OP()
{
  for (int i=1;i<5;i++) if (a[i]==a[i-1]) return true;
  return false;
}

int judge()
{
  for (int i=0;i<5;i++) a[i]=ctoi1(temp[i][0]);
  for (int i=0;i<5;i++) b[i]=ctoi2(temp[i][0]);
  sort(a,a+5);sort(b,b+5);
  if (SF()) return 0;
  if (FOAK()) return 1;
  if (FH()) return 2;
  if (F()) return 3;
  if (S()) return 4;
  if (TOAK()) return 5;
  if (TP()) return 6;
  if (OP()) return 7;
  return 8;
}

int run(int s)
{
  int top=0;
  for (int i=0;i<5;i++)
    if (s&(1<<i))
      strcpy(temp[i],Deck[top++]);
    else
      strcpy(temp[i],Hand[i]);

  return judge();
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",Hand[0])==1)
  {
    for (int i=1;i<5;i++) scanf("%s",Hand[i]);
    for (int i=0;i<5;i++) scanf("%s",Deck[i]);
    
    printf("Hand:");
    for (int i=0;i<5;i++) printf(" %s",Hand[i]);
    printf(" Deck:");
    for (int i=0;i<5;i++) printf(" %s",Deck[i]);
    printf(" Best hand: ");


    id=8;

    for (int i=0;i<(1<<5);i++) id=min(id,run(i));

    printf("%s\n",res[id]);
  }


  return 0;
}
