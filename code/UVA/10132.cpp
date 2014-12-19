/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-24 18:14:42 
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

bool
cmp(const string &s1,const string &s2)
{
  return s1.size()<s2.size();
}

string combine[23];
int score[23];

string s[22333];

char str[2333];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T;
  scanf("%d",&T_T);getchar();getchar();
  
  while (T_T--)
  {
    int n=0;
    int MIN=INF,MAX=0;
    while (gets(str)!=NULL && str[0]!='\0')
    {
      int len=strlen(str);
      MIN=min(MIN,len);
      MAX=max(MAX,len);
      s[n++]=str;
    }
    
    sort(s,s+n);
    int sn=unique(s,s+n)-s;
    sort(s,s+sn,cmp);
    
    int total_length=MIN+MAX;
    int cnt=0;
    
    for (int i=0;i<sn;i++)
    {
      if (s[i].size()!=MIN) break;
      for (int j=sn-1;j>=0;j--)
      {
        if (s[j].size()!=MAX) break;
        combine[cnt++]=s[i]+s[j];
        combine[cnt++]=s[j]+s[i];
      }
    }
    
    memset(score,0,sizeof score);
    
    string temp;
    for (int i=0,j=sn-1;i<sn;i++)
    {
      while (s[j].size()>total_length-s[i].size()) j--;
      for (int k=j;k>=0 && s[k].size()==s[j].size();k--)
      {
        temp=s[i]+s[k];
        for (int t=0;t<cnt;t++)
        {
          if (temp==combine[t])
          {
            score[t]++;
            break;
          }
        }
      }
    }
    
    int the_one=-1;
    for (int i=0;i<cnt;i++)
    {
      if (the_one==-1 || score[the_one]<score[i]) the_one=i;
    }

    printf("%s\n",combine[the_one].c_str());
    if (T_T) putchar('\n');
    
  }
  
  return 0;
}



