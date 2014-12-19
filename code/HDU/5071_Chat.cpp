/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 25 Oct 2014 09:30:24 AM CST
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
#define maxn 8964

using namespace std;

struct __chat
{
  int u;
  long long c;
}chat[maxn];

int TOP,cnt;
map<int,int> MAP;

void Add()
{
  int u;
  scanf("%d",&u);
  if (MAP.count(u)!=0)
  {
    puts("same priority.");
    return ;
  }

  MAP[u]=cnt;
  chat[cnt].u=u;
  chat[cnt].c=0;
  cnt++;

  puts("success.");
}

void Close()
{
  int u;
  scanf("%d",&u);
  if (MAP.count(u)==0)
  {
    puts("invalid priority.");
    return ;
  }

  if (TOP==u) TOP=-1;
  int the_one=MAP[u];
  printf("close %d with "lld".\n",chat[the_one].u,chat[the_one].c);
  for (int i=the_one;i<cnt-1;i++)
  {
    chat[i]=chat[i+1];
    MAP[chat[i].u]=i;
  }
  cnt--;
  
  MAP.erase(u);
}

void Chat()
{
  int w;
  scanf("%d",&w);

  if (cnt==0)
  {
    puts("empty.");
    return ;
  }

  if (TOP!=-1)
    chat[MAP[TOP]].c+=w;
  else
    chat[0].c+=w;

  puts("success.");
}

void Rotate()
{
  int x;
  scanf("%d",&x);
  if (x<1 || x>cnt)
  {
    puts("out of range.");
    return ;
  }

  __chat temp=chat[x-1];
  for (int i=x-1;i>0;i--)
  {
    chat[i]=chat[i-1];
    MAP[chat[i].u]=i;
  }

  chat[0]=temp;
  MAP[temp.u]=0;

  puts("success.");
}

void Prior()
{
  if (cnt==0)
  {
    puts("empty.");
    return ;
  }

  int the_one=0;
  for (int i=1;i<cnt;i++)
    if (chat[the_one].u<chat[i].u) the_one=i;
  
  __chat temp=chat[the_one];
  for (int i=the_one;i>0;i--)
  {
    chat[i]=chat[i-1];
    MAP[chat[i].u]=i;
  }

  chat[0]=temp;
  MAP[temp.u]=0;

  puts("success.");
}

void Choose()
{
  int u;
  scanf("%d",&u);
  if (MAP.count(u)==0)
  {
    puts("invalid priority.");
    return ;
  }

  int the_one=MAP[u];
  __chat temp=chat[the_one];

  for (int i=the_one;i>0;i--)
  {
    chat[i]=chat[i-1];
    MAP[chat[i].u]=i;
  }

  chat[0]=temp;
  MAP[temp.u]=0;

  puts("success.");
}

void Top()
{
  int u;
  scanf("%d",&u);
  
  if (MAP.count(u)==0)
  {
    puts("invalid priority.");
    return ;
  }

  TOP=u;
  puts("success.");
}

void Untop()
{
  if (TOP==-1)
    puts("no such person.");
  else
  {
    TOP=-1;
    puts("success.");
  }
}

char op[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    TOP=-1;
    cnt=0;
    MAP.clear();

    for (int i=0;i<n;i++)
    {
      printf("Operation #%d: ",i+1);
      scanf("%s",op);

      if (strcmp(op,"Add")==0)
        Add();
      else if(strcmp(op,"Close")==0)
        Close();
      else if(strcmp(op,"Chat")==0)
        Chat();
      else if(strcmp(op,"Rotate")==0)
        Rotate();
      else if(strcmp(op,"Prior")==0)
        Prior();
      else if(strcmp(op,"Choose")==0)
        Choose();
      else if(strcmp(op,"Top")==0)
        Top();
      else
        Untop();
    }

    if (TOP!=-1)
      if (chat[MAP[TOP]].c!=0)
        printf("Bye %d: "lld"\n",TOP,chat[MAP[TOP]].c);

    for (int i=0;i<cnt;i++)
      if (chat[i].u!=TOP && chat[i].c>0)
        printf("Bye %d: "lld"\n",chat[i].u,chat[i].c);
  }



  return 0;
}
