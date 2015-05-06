/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 06 May 2015 06:07:39 PM CST
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

char cmd[233];
char url[233];

string q[233];
int f,r;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  f=0;
  r=-1;
  q[++r]=string("http://www.acm.org/");

  int cur=0;

  while (scanf("%s",cmd),strcmp(cmd,"QUIT")!=0)
  {
    if (cmd[0]=='V')
    {
      scanf("%s",url);
      q[r=++cur]=string(url);
      puts(url);
    }
    else if (cmd[0]=='B')
    {
      if (cur==0)
      {
        puts("Ignored");
        continue;
      }
      cur--;
      puts(q[cur].c_str());
    }
    else
    {
      if (cur==r)
      {
        puts("Ignored");
        continue;
      }
      cur++;
      puts(q[cur].c_str());
    }
  }



  return 0;
}
