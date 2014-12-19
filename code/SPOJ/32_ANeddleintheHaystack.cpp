/*
 *
 * Author : fcbruce
 *
 * Time : Thu 02 Oct 2014 05:30:53 PM CST
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

void get_prefix(char *P,int nex[])
{
  nex[0]=-1;
  for (int i=1,j=-1;P[i]!=0;i++)
  {
    while (j>-1 && P[j+1]!=P[i]) j=nex[j];
    if (P[j+1]==P[i]) j++;
    nex[i]=j;
  }
}

int KMP(char *P,int nex[])
{
  int res=0;
  char ch;

  get_prefix(P,nex);

  for (int i=0,j=-1;ch=getchar() ,ch!='\n';i++)
  {
    while (j>-1 && P[j+1]!=ch) j=nex[j];
    if (P[j+1]==ch) j++;
    if (P[j+1]=='\0')
    {
      printf("%d\n",i-j);
      res++;
    }
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int l;

  while (~scanf("%d",&l))
  {
    char *P=new char [l+1];
    int *nex=new int [l+1];
    scanf("%s",P);getchar();

    if (KMP(P,nex)==0) puts("");

    delete [] P;
    delete [] nex;
  }


  return 0;
}
