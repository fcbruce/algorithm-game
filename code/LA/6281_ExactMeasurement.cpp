/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 16 Nov 2014 06:40:41 PM CST
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

struct box
{
  double q;
  int id;
  bool operator < (const box &_)const
  {
    return q>_.q;
  }
}b;

vector<box> v[20];
double digit[20];
vector<int> ans;

long long zero[20];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  long long x;
  int n;

  while (scanf(lld"%d",&x,&n)==2)
  {
    for (int i=0;i<20;i++) v[i].clear();
    ans.clear();
    bool ok=true;

    for (int i=0,k;i<n;i++)
    {
      b.id=i+1;
      scanf("%d%lf",&k,&b.q);
      v[k].push_back(b);
    }

    int cnt=0;
    while (x!=0ll)
    {
      digit[cnt++]=x % 10ll;
      x/=10ll;
    }

    for (int i=0;i<cnt;i++)
    {
      sort(v[i].begin(),v[i].end());
      int u=-1,j;
      for (j=0;j<v[i].size();j++)
      {
        if (digit[i]<=0)
        {
          u=j;
          break;
        }

        digit[i]-=v[i][j].q;
        ans.push_back(v[i][j].id);
      }

      if (digit[i]>0) 
      {
        ok=false;
        break;
      }

      digit[i+1]+=digit[i]/10.0;

      if (u==-1) continue;

      for (j=u;j<v[i].size();j++)
      {
        v[i][j].q/=10;
        v[i+1].push_back(v[i][j]);
      }
    }

    if (ok)
    {
      printf("%d\n",(int)ans.size());
      for (int i=0;i<ans.size();i++)
      {
        if (i) putchar(' ');
        printf("%d",ans[i]);
      }
      puts("");
    }
    else
      puts("-1");
  }


  return 0;
}
