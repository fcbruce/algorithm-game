/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 04:53:08 PM CST
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

#define maxm 20007
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int sum[maxn<<2];
int d[maxn];
bool vis[maxn];
int q[maxn];

int n,k;

long long res;

int size[maxn],value[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs_len(int s,int fa,int d,vector<int> &tmp)
{
  tmp.push_back(d);

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa && !vis[v[e]])
    dfs_len(v[e],s,d+w[e],tmp);
}

int calc(vector<int> &v)
{
  int res=0;
  sort(v.begin(),v.end());
  for (int i=0,j=v.size()-1;i<j;)
  {
    if (v[i]+v[j]<=k)
    {
      res+=j-i;
      i++;
    }
    else j--;
  }
  return res;
}

int solve_len(int s)
{
  int res=0;
  vector<int> save;
  save.push_back(0);
  for (int e=fir[s];~e;e=nex[e]) if (!vis[v[e]])
  {
    vector<int> tmp;
    dfs_len(v[e],s,w[e],tmp);
    res+=calc(tmp);
    for (int i=0;i<tmp.size();i++) save.push_back(tmp[i]);
  }
  return calc(save)-res;
}

void dfsroot(int s,int fa,int &root,int n)
{
  size[s]=1;
  value[s]=0;

  for (int e=fir[s];~e;e=nex[e]) if (fa!=v[e] && !vis[v[e]])
  {
    dfsroot(v[e],s,root,n);
    size[s]+=size[v[e]];
    value[s]=max(value[s],size[v[e]]);
  }

  value[s]=max(value[s],n-size[s]);

  if (root==-1 || value[root]>value[s]) root=s;
}

int solve(int s,int fa,int n)
{
  int root=-1;
  dfsroot(s,-1,root,n);
  vis[root]=true;

  int res=0;

  res+=solve_len(root);

  for (int e=fir[root];~e;e=nex[e]) if (!vis[v[e]]) res+=solve(v[e],root,size[v[e]]);

  return res;

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&k)==2 && (n!=0 || k!=0))
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    memset(vis,0,sizeof vis);

    for (int i=1,u,v,w;i<n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
      add_edge(v,u,w);
    }

    printf("%d\n",solve(1,-1,n));
  }



  return 0;
}
