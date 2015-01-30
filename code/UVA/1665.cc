/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 30 Jan 2015 10:25:26 AM CST
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

#define maxm 1000007
#define maxn 1007

using namespace std;

int pre[maxm];
int G[maxn][maxn];
int query[maxm];
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

struct __cell
{
  int v,x,y;
}cell[maxm];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int x,int y)
{
  return root(x)==root(y);
}

inline void merge(int x,int y)
{
  pre[root(x)]=root(y);
}

void init(int n,int m)
{
  for (int i=0;i<n*m;i++)
    pre[i]=i;

  for (int i=0;i<n;i++) for (int j=0;j<m;j++)
  {
    int id=i*m+j;
    cell[id]={G[i][j],i,j};
  }

  sort(cell,cell+n*m,[](const __cell &a,const __cell &b){return a.v>b.v;});

  for (int i=0;i<n*m;i++)
    G[cell[i].x][cell[i].y]=i;
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
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",G[i]+j);
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++) scanf("%d",query+i);

    init(n,m);

    int cnt=n*m;

    for (int i=q-1,j=0;i>=0;i--)
    {
      while (j<n*m && cell[j].v>query[i])
      {
        int x=cell[j].x,y=cell[j].y;
        for (int k=0;k<4;k++)
        {
          int tx=x+dx[k],ty=y+dy[k];
          if (0<=tx && tx<n && 0<=ty && ty<m) if (cell[G[tx][ty]].v>query[i] && !same(j,G[tx][ty]))
          {
            merge(j,G[tx][ty]);
            cnt--;
          }
        }
        
        j++;
      }

      query[i]=cnt-(n*m-j);
    }

    for (int i=0;i<q;i++)
      printf("%d ",query[i]);
    puts("");
  }

  return 0;
}
