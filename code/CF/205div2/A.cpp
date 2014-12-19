/*
 *
 * Author : fcbruce
 *
 * Time : Tue 30 Sep 2014 09:11:36 PM CST
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

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  int X=0,Y=0,x,y;
  bool can_swap=false;
  scanf("%d",&n);

  for (int i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    X+=x;
    Y+=y;
    if (x+y&1) can_swap=true;
  }

  if ((X&1)==0 && (Y&1)==0)
    puts("0");
  else if ((X&1)==1 && (Y&1)==1 && can_swap)
    puts("1");
  else
    puts("-1");


  return 0;
}
