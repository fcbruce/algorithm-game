/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-20 00:43:07 
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
#define maxn 64

using namespace std;

string s[maxn];

bool
cmp(const string &a,const string &b)
{
  return a+b > b+a;
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n;
  
  while (scanf("%d",&n),n)
  {
    for (int i=0;i<n;i++) cin>>s[i];
    
    sort(s,s+n,cmp);
    
    for (int i=0;i<n;i++) cout<<s[i];
    
    putchar('\n');
  }
  
  return 0;
}



