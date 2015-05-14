/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 13 May 2015 08:31:01 PM CST
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

#define maxm 1000007<<2
#define maxn 20007

using namespace std;

const int maxl=2333;
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
  bign(int num)
  {
    *this=num;
  }
  bign(const char *s)
  {
    *this=s;
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

  void clean()
  {
    while (len>1 && s[len-1]==0) len--;
  }

  bign operator * (const bign &b)
  {
    bign c;c.len=len+b.len;
    for (int i=0;i<len;i++)
      for (int j=0;j<b.len;j++)
        c.s[i+j]+=s[i]*b.s[j];

    for (int i=0;i<c.len-1;i++)
    {
      c.s[i+1]+=c.s[i]/mod;
      c.s[i]%=mod;
    }

    c.clean();
    return c;
  }
};

int bign::width=8;
long long bign::mod=100000000ll;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int n;

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int pre[maxn],low[maxn],bccno[maxn];
bool iscut[maxn];
int dfs_clock,bcc_cnt,b_cnt;

int st[maxm];
int top;
vector<int> bcc[maxn];
int e_bcc[maxn];

int tarjan_dfs(int s,int fa)
{
  int lowu=pre[s]=++dfs_clock;
  int child=0;
  for (int e=fir[s];~e;e=nex[e])
  {
    int t=v[e];
    if (t==fa) continue;
    if (!pre[t])
    {
      st[++top]=e;
      child++;
      int lowv=tarjan_dfs(t,s);
      lowu=min(lowu,lowv);
      if (pre[s]<=lowv)
      {
        iscut[s]=true;
        bcc_cnt++;
        bcc[bcc_cnt].clear();
        e_bcc[bcc_cnt]=0;
        for (;;)
        {
          e_bcc[bcc_cnt]++;
          int x=st[top--];
          if (bccno[u[x]]!=bcc_cnt)
          {
            bcc[bcc_cnt].push_back(u[x]);
            bccno[u[x]]=bcc_cnt;
          }
          if (bccno[v[x]]!=bcc_cnt)
          {
            bcc[bcc_cnt].push_back(v[x]);
            bccno[v[x]]=bcc_cnt;
          }
          if (u[x]==s && v[x]==t) break;
        }
      }
    }
    else
    {
      if (pre[t]<pre[s] && t!=fa)
      {
        st[++top]=e;
        lowu=min(lowu,pre[t]);
      }
    }
  }
  if (fa<0 && child==1 ) iscut[s]=0;
  return lowu;
}

void find_bcc(int n)
{
  memset(pre,0,sizeof pre);
  memset(iscut,0,sizeof iscut);
  memset(bccno,0,sizeof bccno);
  dfs_clock=bcc_cnt=0;
  for (int i=1;i<=n;i++)
    if (!pre[i]) tarjan_dfs(i,-1);
}

char s[maxn<<4];

int pr[maxn];

int scnt;

int root(int x)
{
  if (x==pr[x]) return x;
  return pr[x]=root(pr[x]);
}

inline bool same(int u,int v)
{
  return root(u)==root(v);
}

inline void merge(int u,int v)
{
  if (same(u,v)) return ;
  pr[root(u)]=root(v);
  scnt--;
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int m;
  scanf("%d%d",&n,&m);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=1;i<=n;i++)
  {
    pr[i]=i;
  }

  scnt=n;

  while (m--)
  {
    int k;
    scanf("%d",&k);

    int last=-1;
    while (k--)
    {
      int v;
      scanf("%d",&v);
      if (last>0)
      {
        add_edge(last,v);
        add_edge(v,last);
        merge(last,v);
      }
      last=v;
    }
  }
  

  if (scnt!=1)
  {
    puts("0");
    return 0;
  }

  find_bcc(n);

  bign res(1);


  for (int i=1;i<=bcc_cnt;i++)
  {
    if ((int)bcc[i].size()!=e_bcc[i])
    {
      if (bcc[i].size()==2 && e_bcc[i]==1) continue;
      res=0;
      break;
    }
    bign a(bcc[i].size()+1);
    res=res*a;
  }

  res.str(s);
  puts(s);


  return 0;
}
