/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-20 22:55:29 
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

vector<pair<int,int> > v1,v2;

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n;
  
  while (scanf("%d",&n),n)
  {
    v1.clear();
    v2.clear();
    
    for (int i=0,x,y;i<n;i++)
    {
      scanf("%d%d",&x,&y);
      v1.push_back(make_pair(x,y));
      v2.push_back(make_pair(y,x));
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    if (v1==v2)
      puts("YES");
    else
      puts("NO");
  }
  
  return 0;
}



