/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 06 Aug 2015 08:45:46 AM CST
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
#define maxn 100007

using namespace std;

struct Node
{
  int v,minv,maxv;
  double sum,cnt;
  Node *children[2];
  Node *closest;
  Node *leftest;
  bool operator > (const Node &rhs) const
  {
    return v>rhs.v;
  }
}node[maxn];

double sum,cnt;

inline void init(int n)
{
  for (int i=1;i<=n;i++) node[i].children[0]=node[i].children[1]=NULL;
}

inline void add_edge(int s,int t,int v)
{
  node[t].v=node[t].minv=node[t].maxv=v;
  for (int i=0;i<2;i++) if (node[s].children[i]==NULL)
  {
    node[s].children[i]=node+t;
    if (i==1 && *(node[s].children[0]) > *(node[s].children[1]))
      swap(node[s].children[0],node[s].children[1]);
    break;
  }
}

void build(Node *s)
{
  s->sum=s->cnt=0;
  for (int i=0;i<2;i++)
  {
    if (s->children[i]!=NULL) 
    {
      build(s->children[i]);
      s->minv=min(s->minv,s->children[i]->minv);
      s->maxv=max(s->maxv,s->children[i]->maxv);
    }
  }
}


struct save
{
  int v;
  Node* p;
  bool operator < (const save &rhs) const
  {
    return v<rhs.v;
  }
};

vector<save> order;

Node * dfs(Node *s)
{
  s->closest=NULL;
  s->leftest=s;

  if (s->children[0]!=NULL)
  {
    if (s->children[1]!=NULL)
    {
      s->children[0]->sum+=s->children[1]->minv+s->sum;
      s->children[0]->cnt+=1+s->cnt;
    }
    dfs(s->children[0]);
    s->leftest=s->children[0]->leftest;
  }

  order.push_back({s->v,s});

  if (s->children[1]!=NULL)
  {
    if (s->children[0]!=NULL)
    {
      s->children[1]->sum+=s->children[0]->maxv+s->sum;
      s->children[1]->cnt+=1+s->cnt;
    }
    s->closest=dfs(s->children[1]);
  }

  if (s->closest==NULL) s->closest=s;

  return s->leftest;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,root=1;
  scanf("%d",&n);

  init(n);

  for (int i=1,f,v;i<=n;i++)
  {
    scanf("%d%d",&f,&v);
    if (f>0) add_edge(f,i,v);
    else 
    {
      root=i;
      node[i].v=node[i].minv=node[i].maxv=v;
    }

  }
  build(node+root);

  dfs(node+root);

  int m;
  scanf("%d",&m);

  while (m--)
  {
    int q;
    scanf("%d",&q);
    auto res = lower_bound(order.begin(),order.end(),(save){q,NULL});
    if (res!=order.begin()) res--;
    auto p=res->p->closest;
    printf("%.10f\n",p->sum/p->cnt);
  }



  return 0;
}
