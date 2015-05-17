/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 11:54:39 AM CST
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
#define maxn 256

using namespace std;

bool G[maxn][maxn];
char s[maxn];

inline void insert_graph(char *s)
{
  G[s[0]][s[strlen(s)-1]]=true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",s)==1)
  {
    memset(G,0,sizeof G);
    insert_graph(s);
    while (scanf("%s",s),s[0]!='0') insert_graph(s);
    for (int k=0;k<maxn;k++) for (int i=0;i<maxn;i++) if (G[i][k])
      for (int j=0;j<maxn;j++) G[i][j]|=G[i][k]&G[k][j];

    puts(G['b']['m']?"Yes.":"No.");
  }



  return 0;
}
