/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 14 Feb 2015 11:12:17 AM CST
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

#define maxm 6464
#define maxn 10

using namespace std;

int data[maxn][maxm];
char buff[maxm];
int cnt[maxm];

int d,s,b;

bool recover(int T)
{
  for (int j=0;j<s*b;j++)
  {
    if (cnt[j]>1) return false;

    int res=0,id=-1;
    for (int i=0;i<d;i++) 
      if (data[i][j]>=0) res^=data[i][j];
      else id=i;

    if (id==-1)
    {
      if (res!=T) 
        return false;
    }
    else
    {
      data[id][j]=res^T;
    }
  }

  return true;
}

void init()
{
  for (int j=0,i=-1;j<s*b;j++)
  {
    if (j%s==0) i++;
    data[i%d][j]=-1;
  }
}

void print()
{
  printf("valid, contents are: ");
  init();
  int res=0,cnt=0;
  for (int i=0;i<b;i++) for (int j=0;j<d;j++) for (int k=0;k<s;k++) if (data[j][i*s+k]>=0)
  {
    res=res<<1|data[j][i*s+k];
    cnt++;
    if (cnt==4)
    {
      printf("%X",res);
      res=cnt=0;
    }
  }
  if (cnt>0)
  {
    res<<=4-cnt;
    printf("%X",res);
  }
  putchar('\n');
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d",&d),d!=0)
  {
    scanf("%d %d",&s,&b);
    char op;
    scanf(" %c",&op);
    memset(cnt,0,sizeof cnt);
    memset(data,-1,sizeof data);
    for (int i=0;i<d;i++) 
    {
      scanf("%s",buff);
      for (int j=0;j<s*b;j++)
      {
        if (buff[j]=='x') cnt[j]++;
        else data[i][j]=buff[j]-'0';
      }
    }

    printf("Disk set %d is ",++__);

    if (recover(op=='E'?0:1)) print();
    else puts("invalid.");



  }



  return 0;
}
