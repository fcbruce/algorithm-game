/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 11:05:24 AM CST
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

long long f[55];
map<long long,bool> s;

inline int ReadInt()  
{  
  int flag=0;  
  int data=0;  
  char ch=getchar();  
  while (ch<'0' || ch>'9')  
  {  
    if (ch=='-') flag=1;  
    ch=getchar();  
  }  
  do  
  {  
    data=data*10+ch-'0';  
    ch=getchar();  
  }while (ch>='0' && ch<='9');  
  if (flag) data=-data;  
  return data;  
}  

bool dfs(long long x)
{
  if (s.count(x)!=0) return s[x];

  int id=lower_bound(f,f+55,x)-f;
  if (f[id]==x)
    return s[x]=true;

  for (int i=3;sqr(f[i])<=x;i++) if (x%f[i]==0)
  {
    if (dfs(x/f[i])) return s[x]=true;
  }

  return s[x]=false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  f[0]=0;f[1]=1;
  for (int i=2;i<55;i++) f[i]=f[i-2]+f[i-1];

  int T_T;
  scanf("%d",&T_T);

  while (T_T-->0)
  {
    long long n=ReadInt();

    if (dfs(n)) puts("Yes");
    else puts("No");
  }



  return 0;
}
