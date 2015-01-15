/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 06:32:40 PM CST
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

int a[6],b[6],v[12];
pair<int,int> p[6];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",a+0,b+0)==2)
  {
    for (int i=1;i<6;i++) scanf("%d%d",a+i,b+i);
    for (int i=0;i<6;i++) if (a[i]>b[i]) swap(a[i],b[i]);
    for (int i=0;i<6;i++) p[i]={a[i],b[i]};
    sort(p,p+6);
    if ([&](){
        if (p[0]!=p[1] || p[2]!=p[3] || p[4]!=p[5]) return false;
        for (int i=0;i<6;i++) v[i]=a[i],v[i+6]=b[i];
        sort(v,v+12);
        return (unique(v,v+12)-v)<=3;
        }())
      puts("POSSIBLE");
    else
      puts("IMPOSSIBLE");
      
  }


  return 0;
}
