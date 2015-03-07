/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Mar 2015 07:13:59 PM CST
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
#define maxn 1000007

using namespace std;

long long a[maxn];
long long s[2][maxn];
int n;

set<long long> ex[2];

inline int ReadInt()  
{  
    int flag=0;  
    char ch = getchar();  
    int data = 0;  
    while (ch < '0' || ch > '9')  
    {  
        if(ch=='-') flag=1;  
        ch = getchar();  
    }  
    do  
    {  
        data = data*10 + ch-'0';  
        ch = getchar();  
    }while (ch >= '0' && ch <= '9');  
        if(flag) data=-data;  
        return data;  
}  

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;

  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    for (int i=1;i<=n;i++) a[i]=ReadInt();
    
    s[0][0]=s[0][1]=0;
    for (int i=1;i<=n;i++)
    {
      s[i&1][i]=s[i&1][i-1]+a[i];
      s[(i&1)^1][i]=s[(i&1)^1][i-1]-a[i];
    }

    ex[0].clear();
    ex[1].clear();
    bool ok=false;
    for (int i=0;i<=n;i++)
    {
      int x=(i&1)^1;
      
      if (i==0) continue;
      long long d=s[x][i]-k;
      if (ex[x].count(d)!=0) 
      {
        ok=true;
        break;
      }
      ex[x].insert(s[x][i]);

      x^=1;
      d=s[x][i]-k;
      if (ex[x].count(d)!=0) 
      {
        ok=true;
        break;
      }
      
    }

    printf("Case #%d: ",++__);
    if (ok) puts("Yes.");
    else puts("No.");
  }



  return 0;
}
