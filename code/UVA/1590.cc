/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 13 Feb 2015 09:58:28 AM CST
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

struct IP
{
  int x[4];

  void receive()
  {
    char buff[64];
    scanf("%s",buff);
    for (int i=0;buff[i]!='\0';i++) if (buff[i]=='.') buff[i]=' ';
    sscanf(buff,"%d %d %d %d",x,x+1,x+2,x+3);
  }

  void print()
  {
    printf("%d.%d.%d.%d\n",x[0],x[1],x[2],x[3]);
  }
}ip[maxn],address,mask;

bool same(int x,int y,int m)
{
  for (int i=1;i<m;i++)
    if ((ip[i].x[x]&1<<y) != (ip[0].x[x]&1<<y)) return false;
  address.x[x]|=ip[0].x[x]&1<<y;
  mask.x[x]|=1<<y;
  return true;
}

void com_pref(int m)
{
  memset(address.x,0,sizeof address.x);
  memset(mask.x,0,sizeof mask.x);

  for (int i=0;i<4;i++) for (int j=7;j>=0;j--)
    if (!same(i,j,m)) return ;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int m;
  
  while (scanf("%d",&m)==1)
  {
    for (int i=0;i<m;i++) ip[i].receive();

    com_pref(m);

    address.print();
    mask.print();
  }



  return 0;
}
