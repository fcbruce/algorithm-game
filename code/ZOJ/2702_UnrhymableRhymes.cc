/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 11 Mar 2015 07:34:29 PM CST
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
#define maxn 8964

using namespace std;

int pre[maxn],nex[maxn];
map<int,int> pos;
vector<int> res;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    pos.clear();
    for (int i=0;i<n;i++)
    {
      int v;
      scanf("%d",&v);
      nex[i]=-1;
      if (pos.count(v)!=0)
      {
        pre[i]=pos[v];
        nex[pos[v]]=i;
      }
      else
      {
        pre[i]=-1;
      }
      pos[v]=i;
    }

    res.clear();
    
    for (int i=0;i<n;)
    {
      int j=i+1;
      while (j<n && pre[j]==-1) j++;
      if (j==n) break;
      else if (nex[j]!=-1) pre[nex[j]]=-1;
      
      int k=j+1;
      while (k<n && pre[k]==-1) k++;
      if (k==n) break;
      else if (nex[k]!=-1) pre[nex[k]]=-1;

      res.push_back(pre[j]+1);
      res.push_back(j+1);
      res.push_back(pre[k]+1);
      res.push_back(k+1);

      for (;i<=k;i++) if (nex[i]!=-1) pre[nex[i]]=-1;
    }

    sort(res.begin(),res.end());
    printf("%zi",res.size()/4);
    for (size_t i=0;i<res.size();i++)
    {
      if (i%4==0) puts("");
      else putchar(' ');
      printf("%d",res[i]);
    }
    puts("\n");
  }



  return 0;
}
