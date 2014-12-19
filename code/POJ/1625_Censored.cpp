/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 20 Nov 2014 11:43:12 AM CST
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
#define maxn 512

using namespace std;

unsigned char dict[64],P[16];
char str[233];

int q[maxn];

const int maxl = 16;
struct bign
{
  static int width;
  static long long mod;
  int len;
  long long s[maxl];

  bign()
  {
    memset(s,0,sizeof s);
    len=1;
  }

  bign operator = (int num)
  {
    char s[maxl];
    sprintf(s,"%d",num);
    *this=s;
    return *this;
  }

  bign operator = (const char *s)
  {
    int l=strlen(s);
    len=0;
    for (int i=l-1;i>=0;i-=width,len++)
    {
      (*this).s[len]=0;
      for (int j=max(0,i-width+1);j<=i;j++)
        (*this).s[len]=(*this).s[len]*10+s[j]-'0';
    }

    return *this;
  }

  void str(char *s)
  {
    char format[10];
    sprintf(format,"%%0%d%s",width,lld+1);
    for (int i=len-1,j=0;i>=0;i--,j++)
      sprintf(s+j*width,format,(*this).s[i]);

    int j=0;
    while (s[j]=='0' && s[j+1]!='\0') j++;
    strcpy(s,s+j);
  }

  bign operator + (const bign &b)const
  {
    bign c;
    c.len=0;
    long long g=0ll;
    for (itn i=0;g!=0ll || i<max(len,b.len);i++)
    {
      long long x=g;
      if (i<len) x+=s[i];
      if (i<b.len) x+=b.s[i];
      c.s[c.len++]=x%mod;
      g=x/mod;
    }
    
    return c;
  }

}dp[2][maxn];

int bign::width=8;
long long bign::mod=100000000ll;

const int maxsize = 50;
struct ACauto
{
  int ch[maxn][maxsize];
  bool val[maxn];
  int nex[maxn];
  int sz,maxs;

  ACauto()
  {
    memset(ch[0],0,sizeof ch[0]);
    val[0]=false;
    sz=1;
  }

  int idx(unsigned char c)
  {
    for (int i=0;i<maxs;i++)
      if (dict[i]==c) return i;
    return -1;
  }

  void insert(const unsigned char *s)
  {
    int u=0;
    for (int i=0;s[i]!='\0';i++)
    {
      int c=idx(s[i]);
      if (ch[u][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        val[sz]=false;
        ch[u][c]=sz++;
      }
      u=ch[u][c];
    }
    val[u]=true;
  }

  void get_fail()
  {
    int f=0,r=-1;
    nex[0]=0;
    for (int c=0;c<maxs;c++)
    {
      int u=ch[0][c];
      if (u!=0)
      {
        nex[u]=0;
        q[++r]=u;
      }
    }

    while (f<=r)
    {
      int x=q[f++];
      for (int c=0;c<maxs;c++)
      {
        int u=ch[x][c];
        if (u==0)
        {
          ch[x][c]=ch[nex[x]][c];
          continue;
        }
        q[++r]=u;
        int v=nex[x];
        nex[u]=ch[v][c];
        val[u]|=val[nex[u]];
      }
    }
  }

  bign DP(int l)
  {
    for (int i=0;i<sz;i++) dp[0][i]=0;
    dp[0][0]=1;
    int x=1;
    for (int i=0;i<l;i++,x^=1)
    {
      for (int j=0;j<sz;j++) dp[x][j]=0;
      for (int j=0;j<sz;j++)
      {
        for (int c=0;c<maxs;c++)
        {
          if (val[ch[j][c]]) continue;
          dp[x][ch[j][c]]=dp[x][ch[j][c]]+dp[x^1][j];
        }
      }
    }

    bign total;
    for (int i=0;i<sz;i++)
      total=total+dp[x^1][i];

    return total;
  }
}acauto;

void read(unsigned char *P)
{
  int i=0;
  while ((P[i]=getchar())!='\n') i++;
  P[i]=0;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,p;
  scanf("%d%d%d",&n,&m,&p);getchar();
  acauto.maxs=n;

  for (int i=0;i<n;i++) dict[i]=getchar();
  getchar();

  for (int i=0;i<p;i++)
  {
    read(P); 
    acauto.insert(P);
  }

  acauto.get_fail();

  acauto.DP(m).str(str);

  printf("%s\n",str);

  return 0;
}
