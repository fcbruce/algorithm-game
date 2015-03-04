/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 04 Mar 2015 10:11:48 AM CST
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

char buff[233];

map<string,int> software;
map<int,int> timepoint;
int time__;

struct item
{
  int tp;
  int installed;
  int be_depended;
  string name;
}items[8964];

vector<int> nex[8964];

inline void add_edge(int s,int t)
{
  nex[s].push_back(t);
}

inline void init(string &s)
{
  auto id=software.size();
  items[id]={0,0,0,s};
  software[s]=id;
  nex[id].clear();
}

void depend()
{
  stringstream sin(buff);
  string s;
  sin>>s;
  sin>>s;
  itn u;
  if (software.count(s)==0) init(s);
  u=software[s];

  while (sin>>s)
  {
    itn v;
    if (software.count(s)==0) init(s);
    v=software[s];
    add_edge(u,v);
  }
}

void installing(int u)
{
  items[u].be_depended++;
  if (items[u].installed!=0) return ;

  for (auto &e : nex[u])
    installing(e);

  items[u].installed=1;
  items[u].tp=++time__;
  timepoint[time__]=u;

  printf("   Installing %s\n",items[u].name.c_str());
}

void install()
{
  stringstream sin(buff);
  string s;
  sin>>s;
  sin>>s;
  itn u;
  if (software.count(s)==0) init(s);
  u=software[s];

  if (items[u].installed!=0)
  {
    printf("   %s is already installed.\n",s.c_str());
    return ;
  }

  for (auto &e : nex[u])
    installing(e);

  items[u].installed=2;
  items[u].tp=++time__;
  timepoint[time__]=u;

  printf("   Installing %s\n",s.c_str());
}

void removing(int u)
{
  if (items[u].installed==0) return;

  items[u].be_depended--;
  if (items[u].be_depended!=0) return ;
  if (items[u].installed==2) return;

  items[u].installed=0;
  timepoint.erase(items[u].tp);
  printf("   Removing %s\n",items[u].name.c_str());

  for (auto &e : nex[u]) 
    removing(e);
}


void remove()
{
  stringstream sin(buff);
  string s;
  sin>>s;
  sin>>s;
  itn u;
  if (software.count(s)==0) init(s);
  u=software[s];

  if (items[u].installed==0)
  {
    printf("   %s is not installed.\n",s.c_str());
    return ;
  }

  if (items[u].be_depended!=0)
  {
    printf("   %s is still needed.\n",s.c_str());
    return ;
  }

  items[u].installed=0;
  timepoint.erase(items[u].tp);
  printf("   Removing %s\n",s.c_str());

  for (auto &e : nex[u])
    removing(e);
}

void List()
{
  for (auto &e : timepoint)
    printf("   %s\n",items[e.second].name.c_str());
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  time__=0;
  
  while (fgets(buff,233,stdin),buff[0]!='E')
  {
    printf("%s",buff);
    switch (buff[0])
    {
      case 'D':
        depend();
        break;
      case 'I':
        install();
        break;
      case 'R':
        remove();
        break;
      case 'L':
        List();
        break;
    }
  }

  printf("%s",buff);

  return 0;
}
