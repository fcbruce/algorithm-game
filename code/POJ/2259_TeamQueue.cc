/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 09:09:28 PM CST
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

#define maxm 1000007
#define maxn 10007

using namespace std;

char cmd[23];
int s[maxm];
bool appear[maxm];
int pos[maxn];
int q[maxn<<4];
int f,r;
queue<int> tq[maxn];
int cnt;

void pop()
{
  int id=q[f];
  printf("%d\n",tq[id].front());
  tq[id].pop();
  if (tq[id].empty())
  {
    pos[id]=-1;
    f++;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  int __=0;

  while (scanf("%d",&n),n!=0)
  {
    printf("Scenario #%d\n",++__);
    f=0;
    r=-1;
    cnt=0;
    memset(s,-1,sizeof s);
    memset(appear,0,sizeof appear);
    for (int i=0;i<n;i++)
    {
      int k;
      scanf("%d",&k);
      while (!tq[k].empty()) tq[k].pop();
      for (int j=0;j<k;j++)
      {
        itn v;
        scanf("%d",&v);
        s[v]=i;
      }
    }
    
    memset(pos,-1,sizeof pos);

    while (scanf("%s",cmd),strcmp(cmd,"STOP")!=0)
    {
      if (cmd[0]=='D') pop();
      else
      {
        int v;
        scanf("%d",&v);
        int id=s[v];
        if (appear[v] || id==-1) continue;

        if (pos[id]!=-1)
        {
          tq[id].push(v);
        }
        else
        {
          pos[id]=id;
          q[++r]=id;
          while (!tq[id].empty()) tq[id].pop();
          tq[id].push(v);
        }
      }
    }

    puts("");

  }



  return 0;
}
