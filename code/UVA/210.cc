/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 28 Feb 2015 04:30:06 PM CST
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

#define maxm 2333
#define maxn 2333

using namespace std;

int dq[maxm],q[maxm];
int df,dr,qf,qr;

int var[26],pos[maxn];
int t[5],n,Q;

bool locked;

char buff[maxn][15];

void run(int pid)
{
  int remain=Q;

  while (remain>0)
  {
    char *line=buff[pos[pid]];
    
    switch (line[2])
    {
      case '=':
        sscanf(line+4,"%d",var+line[0]-'a');
        remain-=t[0];
        break;
      case 'i':
        printf("%d: %d\n",pid+1,var[line[6]-'a']);
        remain-=t[1];
        break;
      case 'c':
        if (locked)
        {
          q[++qr]=pid;
          return;
        }
        locked=true;
        remain-=t[2];
        break;
      case 'l':
        locked=false;
        if (qf<=qr)
          dq[--df]=q[qf++];
        remain-=t[3];
        break;
      case 'd':
        return ;
    }

    pos[pid]++;
  }

  dq[++dr]=pid;
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
    scanf("%d",&n);
    for (int i=0;i<5;i++) scanf("%d",t+i);
    scanf("%d",&Q);

    int cnt=0,line=0;
    pos[0]=0;
    do
    {
      fgets(buff[line],64,stdin);
      if (buff[line][2]=='d') pos[++cnt]=line+1;
      line++;
    }while (cnt<n);

    df=1000,dr=999;
    for (int i=0;i<n;i++) dq[++dr]=i;
    qf=0;qr=-1;

    locked=false;
    memset(var,0,sizeof var);
    while (df<=dr)
    {
      int x=dq[df++];
      run(x);
    }

    if (T_T>0) puts("");
  }



  return 0;
}
