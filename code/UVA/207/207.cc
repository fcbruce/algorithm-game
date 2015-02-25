/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 23 Feb 2015 06:18:32 PM CST
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

const int maxsize = 70;

char buff[233];

struct player
{
  char name[22];
  int sc[4];
  int rnds,sc36,sc72,ranking;
  bool dq,ok;

  void read()
  {
    fgets(buff,34,stdin);
    strncpy(name,buff,20);
    name[20]='\0';
    ok=(strchr(name,'*')==NULL);
    dq=false;
    sc36=sc72=0;
    for (int i=0;i<4;i++)
    {
      if (sscanf(buff+20+i*3,"%d",sc+i)==1)
      {
        rnds=i+1;
        sc72+=sc[i];
        if (i<2) sc36+=sc[i];
      }
      else
      {
        dq=true;
        if (i<2) sc36=INF;
        break;
      }
    }
  }
}players[233];

int n;
double total;
double rate[233],money[233];

bool ex[233];

int cnt[233],cnt_[233];

int make_the_cut()
{
  int i=maxsize;
  while (i<n && players[i].sc36==players[i-1].sc36) i++;
  while (players[i-1].sc36 == INF) i--;
  return i;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);getchar();

  while (T_T--)
  {
    getchar();

    scanf("%lf",&total);
    for (int i=0;i<maxsize;i++) scanf("%lf",rate+i);

    scanf("%d",&n);getchar();

    for (int i=0;i<n;i++) players[i].read();

    sort(players,players+n,[](const player &a,const player &b){return a.sc36<b.sc36;});

    n=make_the_cut();

    auto cmp=[](const player &a,const player &b)
    {
      if (a.dq && b.dq)
      {
        if (a.rnds!=b.rnds) return a.rnds>b.rnds;
        if (a.sc72!=b.sc72) return a.sc72<b.sc72;
        return strcmp(a.name,b.name)<0;
      }

      if (a.dq) return false;
      if (b.dq) return true;
      if (a.sc72!=b.sc72) return a.sc72<b.sc72;
      return strcmp(a.name,b.name)<0;
    };

    sort(players,players+n,cmp);

    int ranking=0;
    memset(money,0,sizeof money);
    memset(cnt,0,sizeof cnt);
    memset(cnt_,0,sizeof cnt_);
    memset(ex,0,sizeof ex);
    cnt_[0]=1;

    for (int i=0,j=0;i<n;i++)
    {
      if (ranking==0 || players[i].sc72!=players[i-1].sc72) ranking+=cnt_[ranking];

      if (players[i].dq) break;

      cnt_[ranking]++;

      if (players[i].ok)
      {
        cnt[ranking]++;
        //pay attention here!
        if (j<70) 
        {
          money[ranking]+=rate[j++];
          ex[ranking]=true;
        }
        players[i].ok=ex[ranking];
      }
      
      players[i].ranking=ranking;
    }

    puts("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won");
    puts("-----------------------------------------------------------------------");

    for (int i=0;i<n;i++)
    {
      printf("%s ",players[i].name);

      if (players[i].dq)
      {
        printf("          ");
        for (int j=0;j<players[i].rnds;j++) printf("%-5d",players[i].sc[j]);
        for (int j=players[i].rnds;j<4;j++) printf("     ");
        puts("DQ");
        continue;
      }

      char add=' ';
      if (cnt[players[i].ranking]>1 && players[i].ok) add='T';
      sprintf(buff,"%d%c",players[i].ranking,add);
      printf("%-10s",buff);
      for (int j=0;j<players[i].rnds;j++) printf("%-5d",players[i].sc[j]);
      
      if (!players[i].ok)
      {
        printf("%d\n",players[i].sc72);
        continue;
      }

      printf("%-10d$",players[i].sc72);
      double cal=total*money[players[i].ranking]/cnt[players[i].ranking]/100.0;
      printf("%9.2f\n",cal);
    }

    if (T_T>0) puts("");
  }

  return 0;
}
