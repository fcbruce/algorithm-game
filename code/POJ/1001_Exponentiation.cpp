/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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
#define maxn 200

using namespace std;


struct bign{ 
  int len, s[maxn]; 

  bign() { 
    memset(s, 0, sizeof(s)); 
    len = 1; 
  } 

  bign(int num) { 
    *this = num; 
  } 

  bign(const char* num) { 
    *this = num; 
  } 

  bign operator = (int num) { 
    char s[maxn]; 
    sprintf(s, "%d", num); 
    *this = s; 
    return *this; 
  } 

  bign operator = (const char* num) { 
    len = strlen(num); 
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0'; 
    return *this; 
  } 

  string str() const { 
    string res = ""; 
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res; 
    if(res == "") res = "0"; 
    return res; 
  } 

  bign operator + (const bign& b) const{ 
    bign c; 
    c.len = 0; 
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) { 
      int x = g; 
      if(i < len) x += s[i]; 
      if(i < b.len) x += b.s[i]; 
      c.s[c.len++] = x % 10; 
      g = x / 10; 
    } 
    return c; 
  } 

  void clean() { 
    while(len > 1 && !s[len-1]) len--; 
  } 

  bign operator * (const bign& b) { 
    bign c; c.len = len + b.len; 
    for(int i = 0; i < len; i++) 
      for(int j = 0; j < b.len; j++) 
        c.s[i+j] += s[i] * b.s[j]; 
    for(int i = 0; i < c.len-1; i++){ 
      c.s[i+1] += c.s[i] / 10; 
      c.s[i] %= 10; 
    } 
    c.clean(); 
    return c; 
  } 

  bign operator - (const bign& b) { 
    bign c; c.len = 0; 
    for(int i = 0, g = 0; i < len; i++) { 
      int x = s[i] - g; 
      if(i < b.len) x -= b.s[i]; 
      if(x >= 0) g = 0; 
      else { 
        g = 1; 
        x += 10; 
      } 
      c.s[c.len++] = x; 
    } 
    c.clean(); 
    return c; 
  } 

  bool operator < (const bign& b) const{ 
    if(len != b.len) return len < b.len; 
    for(int i = len-1; i >= 0; i--) 
      if(s[i] != b.s[i]) return s[i] < b.s[i]; 
    return false; 
  } 

  bool operator > (const bign& b) const{ 
    return b < *this; 
  } 

  bool operator <= (const bign& b) { 
    return !(b > *this); 
  } 

  bool operator == (const bign& b) { 
    return !(b < *this) && !(*this < b); 
  } 

  bign operator += (const bign& b) { 
    *this = *this + b; 
    return *this; 
  } 
}; 

istream& operator >> (istream &in, bign& x) { 
  string s; 
  in >> s; 
  x = s.c_str(); 
  return in; 
} 

ostream& operator << (ostream &out, const bign& x) { 
  out << x.str(); 
  return out; 
} 

char str[10];
char s[maxn];
int n;

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  while (~scanf("%s%d",str,&n))
  {
    char *p=strchr(str,'.');
    int dot=0;
    if (p!=NULL)
    {
      dot=5-(p-str);
    }
    
    double r;
    sscanf(str,"%lf",&r);
    int temp=r*pow(10,dot);
    bign b(temp),ans(1);
    
    for (int i=0;i<n;i++)
    {
      ans=ans*b;
    }
    
    sprintf(s,"%s",ans.str().c_str());
    
    int l=strlen(s);
    dot*=n;
    if (l<=dot)
    {
      putchar('.');
      for (int i=0;i<dot-l;i++) putchar('0');
      while (l && s[l-1]=='0')s[--l]='\0';
      puts(s);
    }
    else
    {
      for (int i=0;i<l-dot;i++) putchar(s[i]);
      int k=l;
      while (l && s[l-1]=='0')s[--l]='\0';
      if (l>k-dot) putchar('.');
      puts(s+k-dot);
    }
  }
  
  return 0;
}



