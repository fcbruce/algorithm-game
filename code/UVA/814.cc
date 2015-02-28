/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 28 Feb 2015 02:48:17 PM CST
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

set<string> addr;

char buff[23333];

inline bool read(string &s)
{
  if (scanf("%s",buff)!=1) return false;
  s=buff;
  return true;
}

inline bool read(int &i)
{
  return scanf("%d",&i)==1;
}

inline void split(string &s,string &user,string &mta)
{
  int k=s.find('@');
  user=s.substr(0,k);
  mta=s.substr(k+1);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  string s,t;
  
  while (read(s) && s!="*")
  {
    read(s);
    int n;
    read(n);
    while (n--)
    {
      read(t);
      addr.insert(t+"@"+s);
    }
  }

  string user1,mta1,user2,mta2;

  while (read(s) && s!="*")
  {
    split(s,user1,mta1);

    vector<string> mta;
    map<string,vector<string> > dest;
    set<string> vis;

    while (read(t) && t!="*")
    {
      split(t,user2,mta2);
      if (vis.count(t)>0) continue;
      vis.insert(t);
      if (dest.count(mta2)==0)
      {
        mta.push_back(mta2);
        dest[mta2]=vector<string>();
      }

      dest[mta2].push_back(t);
    }

    fgets(buff,233,stdin);

    string data;
    while (fgets(buff,233,stdin) && buff[0]!='*')
    {
      data+="     ";
      data+=buff;
    }

    for (auto &i : mta)
    {
      auto &v=dest[i];
      printf("Connection between %s and %s\n",mta1.c_str(),i.c_str());
      printf("     HELO %s\n",mta1.c_str());
      printf("     250\n");
      printf("     MAIL FROM:<%s>\n",s.c_str());
      printf("     250\n");
      bool ok=false;
      for (auto &i : v)
      {
        printf("     RCPT TO:<%s>\n",i.c_str());
        if (addr.count(i)>0)
        {
          ok=true;
          printf("     250\n");
        }
        else printf("     550\n");
      }

      if (ok)
      {
        printf("     DATA\n");
        printf("     354\n");
        printf("%s",data.c_str());
        printf("     .\n");
        printf("     250\n");
      }

      printf("     QUIT\n");
      printf("     221\n");
    }
  }


  return 0;
}
