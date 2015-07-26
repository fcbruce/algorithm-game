/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Nov 2014 08:19:55 PM CST
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
#define maxn 32768

using namespace std;

int q[maxn];

const int maxsize = 256;
struct Acauto
{
  int ch[maxn][maxsize];
  int val[maxn],last[maxn],nex[maxn];
  bool vis[555];
  int sz;
  int cnt;

  Acauto()
  {
    memset(ch,0,sizeof ch);
    val[0]=0;
    sz=1;
  }

  void clear()
  {
    memset(ch,0,sizeof ch);
    val[0]=0;
    sz=1;
  }

  void insert(const int s[],int v=1)
  {
    int u=0;
    for (int i=0;s[i]>=0;i++)
    {
      int c=s[i];
      if (ch[u][c]==0)
      {
        memset(ch[sz],0,sizeof ch[sz]);
        val[sz]=0;
        ch[u][c]=sz++;
      }
      u=ch[u][c];
    }
    val[u]=v;
  }

  void calc(int j)
  {
    if (j!=0)
    {
      if (!vis[val[j]]) {vis[val[j]]=true;cnt++;}
      calc(last[j]);
    }
  }

  void get_fail()
  {
    int f=0,r=-1;
    nex[0]=0;
    for (int c=0;c<maxsize;c++)
    {
      int u=ch[0][c];
      if (u!=0)
      {
        nex[u]=0;
        q[++r]=u;
        last[u]=0;
      }
    }

    while (f<=r)
    {
      int x=q[f++];
      for (int c=0;c<maxsize;c++)
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
        last[u]=val[nex[u]]>0?nex[u]:last[nex[u]];
      }
    }
  }

  int find(const int T [])
  {
    cnt=0;
    memset(vis,0,sizeof vis);
    for (int i=0,j=0;T[i]>=0;i++)
    {
      int c=T[i];
      j=ch[j][c];
      if (val[j]!=0) calc(j);
      else if (last[j]!=0) calc(last[j]);
    }
    return cnt;
  }
}acauto;

int idx(char c)
{
  if (isupper(c)) return c-'A';
  if (islower(c)) return c-'a'+26;
  if (isdigit(c)) return c-'0'+52;
  if (c=='+') return 62;
  return 63;
}

char str[23323];
int obj[23323];
int bi[223232];

void decode(char *str,int obj [])
{
  int l=strlen(str);
  int eq=0;
  
  while (str[l-1]=='=') {eq++;l--;}

  int n=0;
  for (int i=0;i<l;i++)
  {
    int c=idx(str[i]);
    for (int j=5;j>=0;j--)
      bi[n++]=c&(1<<j)?1:0;
  }

  n-=2*eq;

  l=0;
  for (int i=0;i<n;i+=8)
  {
    int res=0;
    for (int j=i;j<i+8;j++)
      res=res*2+bi[j];
    obj[l++]=res;
  }
  obj[l]=-1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    acauto.clear();
    for (int i=0;i<n;i++)
    {
      scanf("%s",str);
      decode(str,obj);
      acauto.insert(obj,i+1);
    }

    acauto.get_fail();

    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
      scanf("%s",str);
      decode(str,obj);
      printf("%d\n",acauto.find(obj));
    }
    putchar('\n');
  }

  return 0;
}
