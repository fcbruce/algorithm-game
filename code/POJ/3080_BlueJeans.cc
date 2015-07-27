/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 03:51:34 PM CST
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

char s[10][maxn];
char tmp[maxn];

void test(int l,int r,string &res,int n)
{
  strcpy(tmp,s[0]+l);
  tmp[r-l]='\0';
  for (int i=1;i<n;i++) if (strstr(s[i],tmp)==NULL) return ;
  if (res.size()<r-l || res.size()==r-l && res>string(tmp)) res=tmp;
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
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%s",s[i]);

    string res;
    for (int i=0;i<60;i++) for (int j=i+2;j<=60;j++)
      test(i,j,res,n);

    if (res=="") res="no significant commonalities";
  
    puts(res.c_str());
  }



  return 0;
}
