/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 24 Jan 2015 08:54:17 AM CST
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
#define maxn 55555

using namespace std;

char str[maxn<<3];
char node[maxn][5];
int vis[maxn];
pair<int,int> tree[maxn];
map<tuple<string,int,int>,int> MAP;
itn cnt;

int analyse(int &p)
{
  char s[5];
  int l=0,r=0,i=0;
  while (islower(str[p])) s[i++]=str[p++];
  s[i]='\0';
  if (str[p]=='(')
  {
    p++;
    l=analyse(p);
    p++;
    r=analyse(p);
    p++;
  }

  tuple<string,int,int> t(string(s),l,r);
  
  int value;

  if (MAP.find(t)!=MAP.end())
    value=MAP[t];
  else
  {
    MAP.insert({t,++cnt});
    value=cnt;
    strcpy(node[value],s);
  }

  tree[value]={l,r};
  return value;
}

void print(int cur)
{
  if (vis[cur]!=0)
  {
    printf("%d",vis[cur]);
    return ;
  }
  vis[cur]=++cnt;
  printf("%s",node[cur]);
  if (tree[cur].first==0) return ;
  putchar('(');
  print(tree[cur].first);
  putchar(',');
  print(tree[cur].second);
  putchar(')');
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
    cnt=0;
    memset(vis,0,sizeof vis);
    MAP.clear();
    scanf("%s",str);
    int p=0;
    int root=analyse(p);
    cnt=0;
    print(root);
    puts("");
  }

  return 0;
}
