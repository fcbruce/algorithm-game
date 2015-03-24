/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 22 Mar 2015 07:33:23 PM CST
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

char s1[23];
int a1,b1;
char s2[23];

char buff1[23],buff2[23];
int a2,b2;
long long l,r;

inline long long ten(int a)
{
  long long res=1;
  for (int i=0;i<a;i++) res*=10;
  return res;
}

long long solve(char *s2)
{
  s1[0]=1;
  s1[1]='\0';
  sscanf(s1,lld,&l);
  sscanf(s2,lld,&r);

  long long res=0;

  int l1=strlen(s1);
  int l2=strlen(s2);
  a1=s1[0]-'0';b1=s1[l1-1]-'0';
  a2=s2[0]-'0';b2=s2[l2-1]-'0';

  for (int i=l1+1;i<l2;i++)
  {
    long long p=9;
    p*=ten(i-2);
    res+=p;
  }

 if (l1<l2) 
 {
   if (a1>=b1) res+=(ten(l1-2))-((l/10)%ten(l1-2));
   else res+=(ten(l1-2))-((l/10)%ten(l1-2))-1;
   res+=(10-a1-1)*ten(l1-2);
 

   if (a2<=b2) res+=(r/10)%ten(l2-2)+1;
   else res+=(r/10)%ten(l2-2);
   res+=(a2-1)*ten(l2-2);
 }
 else
 {
   int x=a1*10+b1;
   int y=a2*10+b2;
   int cnt=0;
   for (int i=a1+1;i<a2;i++) if (x<=i*10+i && i*10+i<=y) cnt++;
   if (a1==a2)
   {
     long long ll=l/10;
     long long rr=r/10;

     if (a1<b1) ll++;
     if (a2<=b2) rr++;

     res+=(rr-ll);
   }
   else
   {
     if (a1>=b1) res+=(ten(l1-2))-((l/10)%ten(l1-2));
     if (a2<=b2) res+=(r/10)%ten(l2-2)+1;
     res+=cnt*ten(l1-2);
   }
 }

 return res;

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
  freopen("ass","w",stdout);
#endif // FCBRUCE

  long long a,b;
  while (scanf(lld lld,&a,&b)==2){

    a--;

    sprintf(buff1,lld,a);
    sprintf(buff2,lld,b);

    printf(lld"\n",solve(buff2)-solve(buff1));



  }



  return 0;
}
