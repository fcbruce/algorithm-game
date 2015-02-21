/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 21 Feb 2015 08:22:50 PM CST
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

char buff[233];

typedef set<int> Set;
map<Set,int> idcache;
vector<Set> setcache;
stack<int> s;

int id(Set x)
{
  if (idcache.count(x)>0) return idcache[x];
  setcache.push_back(x);
  return idcache[x]=setcache.size()-1;
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
    idcache.clear();
    setcache.clear();
    while (!s.empty()) s.pop();
    
    int n;
    scanf("%d",&n);

    while (n--)
    {
      scanf("%s",buff);

      if (buff[0]=='P') s.push(id(Set()));
      else if (buff[0]=='D') s.push(s.top());
      else
      {
        auto x1=setcache[s.top()];s.pop();
        auto x2=setcache[s.top()];s.pop();
        Set x;
        auto ins=inserter(x,x.begin());
        if (buff[0]=='U') set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),ins);
        if (buff[0]=='I') set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),ins);
        if (buff[0]=='A')
        {
          x=x2;
          x.insert(id(x1));
        }

        s.push(id(x));
      }

      printf("%zi\n",setcache[s.top()].size());
    }
    
    puts("***");
  }



  return 0;
}
