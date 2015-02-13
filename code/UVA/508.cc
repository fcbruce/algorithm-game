/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 13 Feb 2015 05:50:45 PM CST
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

#define maxm 107
#define maxn 256

using namespace std;

string cd[maxn];
pair<string,string> wd[maxm];

int n;

string trans(char *s)
{
  string temp;
  for (int i=0;s[i]!='\0';i++)
    temp+=cd[s[i]-'\0'];
  return temp;
}

int dis(string a,string b)
{
  size_t l=min(a.size(),b.size());
  
  string x(a.begin(),a.begin()+l);
  string y(b.begin(),b.begin()+l);

  if (x==y) return abs((int)a.size()-(int)b.size());
  return INF;
}

string decode(char *s)
{
  int MIN=INF;
  string res;
  for (int i=0;i<n;i++)
  {
    int d=dis(s,wd[i].second);
    if (d<MIN)
    {
      MIN=d;
      res=wd[i].first;
    }
    else if (d==0) return res+"!";
  }

  if (MIN>0) return res+"?";
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  char buff1[233],buff2[233];

  while (scanf("%s",buff1),buff1[0]!='*')
  {
    scanf("%s",buff2);
    cd[buff1[0]-'\0']=string(buff2);
  }


  n=0;
  while (scanf("%s",buff1),buff1[0]!='*')
  {
    wd[n++]={string(buff1),trans(buff1)};
  }

  while (scanf("%s",buff1),buff1[0]!='*')
  {
    puts(decode(buff1).c_str());
  }

  return 0;
}
