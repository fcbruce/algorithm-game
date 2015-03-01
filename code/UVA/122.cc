/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 01 Mar 2015 02:35:47 PM CST
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

struct __node
{
  int v;
  int lc,rc;
}node[512];

int cnt;

char buff[233];

vector<int> v;

bool err;

void add_node(int &cur,int v,char *s)
{
  if (cur==-1) 
  {
    cur=cnt++;
    node[cur]={-1,-1,-1};
  }

  if (s[0]==')')
  {
    if (node[cur].v!=-1) err=true;
    node[cur].v=v;
    return ;
  }

  if (s[0]=='L')
  {
    add_node(node[cur].lc,v,s+1);
    return ;
  }

  if (s[0]=='R')
  {
    add_node(node[cur].rc,v,s+1);
    return ;
  }
}

int q[512];

bool bfs(int s)
{
  int f,r;
  q[f=r=0]=s;
  v.clear();
  
  while (f<=r)
  {
    int x=q[f++];
    if (node[x].v==-1) return false;
    v.push_back(node[x].v);
    
    if (node[x].lc!=-1) q[++r]=node[x].lc;
    if (node[x].rc!=-1) q[++r]=node[x].rc;
  }

  return true;
}

void print()
{
  bool fir=true;
  for (auto i : v)
  {
    if (!fir) putchar(' ');
    fir=false;
    printf("%d",i);
  }
  puts("");
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",buff)==1)
  {
    int root=-1;
    cnt=0;
    err=false;

    do
    {
      int v;
      sscanf(buff+1,"%d",&v);
      add_node(root,v,strchr(buff,',')+1);
    } while (scanf("%s",buff),strcmp(buff,"()")!=0);

    if (!err && bfs(root)) print();
    else puts("not complete");
  }

  return 0;
}
