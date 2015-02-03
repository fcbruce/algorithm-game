/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 02 Feb 2015 04:33:39 PM CST
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
#define eps 1e-6

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 

using namespace std;

char buff[233];

int ranking(int);

inline int dcmp(double a,double b)
{
  if (fabs(a-b)<eps) return 0;
  return a>b?1:-1;
}

struct student
{
  string SID,CID,NAME;
  int score[4],total;
  double average;
  int passed;

  void set(char *sid,char *cid,char *name)
  {
    SID=sid;
    CID=cid;
    NAME=name;
  }

  void get_score()
  {
    total=0;
    passed=0;
    for (int i=0;i<4;i++)
    {
      scanf("%d",score+i);
      if (score[i]>=60) ++passed;
      total+=score[i];
    }
    average=total/4.0;
  }

  bool match(char *buff)
  {
    string temp(buff);
    return SID==temp || NAME==temp;
  }

  void show()
  {
    printf("%d %s %s %s ",ranking(total),SID.c_str(),CID.c_str(),NAME.c_str());
    for (int i=0;i<4;i++) printf("%d ",score[i]);
    printf("%d %.2f\n",total,average+eps);
  }
};

list<student> Link;
set<string> SET;

int score[5];
int single_fail[4],single_pass[4];
int number_pass[5];

const char subject[][64]={"Chinese","Mathematics","English","Programming"};

int ranking(int s)
{
  int cnt=1;
  for (auto iter=Link.begin();iter!=Link.end();++iter) if (iter->total>s) cnt++;
  return cnt;
}

bool detect(char *_sid)
{
  string sid(_sid);
  if (SET.count(sid)>0)
  {
    puts("Duplicated SID.");
    return true;
  }
  SET.insert(sid);
  return false;
}

void add()
{
  char SID[64],CID[64],NAME[64];
  while (puts("Please enter the SID, CID, name and four scores. Enter 0 to finish."),scanf("%s",SID),strcmp(SID,"0")!=0)
  {
    student s;
    scanf("%s %s",CID,NAME);
    s.set(SID,CID,NAME);
    s.get_score();
    if (detect(SID)) continue;
    Link.push_back(s);
  }
}

void remove()
{
  while (puts("Please enter SID or name. Enter 0 to finish."),scanf("%s",buff),strcmp(buff,"0")!=0)
  {
    int cnt=0;

    for (auto iter=Link.begin();iter!=Link.end();++iter) if (iter->match(buff))
    {
      SET.erase(iter->SID);
      Link.erase(iter);
      --iter;
      cnt++;
    }

    printf("%d student(s) removed.\n",cnt);
  }
}

void query()
{
  while (puts("Please enter SID or name. Enter 0 to finish."),scanf("%s",buff),strcmp(buff,"0")!=0)
    for (auto iter=Link.begin();iter!=Link.end();++iter) if (iter->match(buff))
      iter->show();
}

void statistics()
{
  puts("Please enter class ID, 0 for the whole statistics.");
  memset(score,0,sizeof score);
  memset(number_pass,0,sizeof number_pass);
  memset(single_pass,0,sizeof single_pass);
  memset(single_fail,0,sizeof single_fail);
  scanf("%s",buff);
  string CID(buff);
  int cnt=0;
  for (auto iter=Link.begin();iter!=Link.end();++iter) if (CID=="0" || CID==iter->CID)
  {
    cnt++;
    number_pass[iter->passed]+=1;
    for (int i=0;i<4;i++)
    {
      score[i]+=iter->score[i];
      if (iter->score[i]>=60) single_pass[i]++;
      else single_fail[i]++;
    }
  }
  
  for (int i=0;i<4;i++)
  {
    puts(subject[i]);
    printf("Average Score: %.2f\n",(double)score[i]/cnt+eps);
    printf("Number of passed students: %d\n",single_pass[i]);
    printf("Number of failed students: %d\n",single_fail[i]);
    puts("");
  }

  puts("Overall:");
  int total=number_pass[4];
  printf("Number of students who passed all subjects: %d\n",total);
  for (int i=3;i>0;--i)
  {
    total+=number_pass[i];
    printf("Number of students who passed %d or more subjects: %d\n",i,total);
  }
  printf("Number of students who failed all subjects: %d\n",number_pass[0]);
  puts("");
}

void menu()
{
  puts("Welcome to Student Performance Management System (SPMS).");
  puts("");
  puts("1 - Add");
  puts("2 - Remove");
  puts("3 - Query");
  puts("4 - Show ranking");
  puts("5 - Show Statistics");
  puts("0 - Exit");
  puts("");
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
  freopen("/home/fcbruce/code/out","w",stdout);
#endif // FCBRUCE

  for (;;)
  {
    menu();
    itn choice;
    scanf("%d",&choice);
    if (choice==0) break;
    switch (choice)
    {
      case 1:
        add();
        break;
      case 2:
        remove();
        break;
      case 3:
        query();
        break;
      case 4:
        puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
        break;
      case 5:
        statistics();
        break;
      default:
        break;
    }
  }



  return 0;
}
