#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

char word[100005][205];

int cmp(const void *x,const void *y)
{
  return strcmp((char *)x,(char *)y);
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("t","r",stdin);
  #endif

  int c,cnt=0,k=0;

  while ((c=getchar())!=EOF)
  {
    if (isalpha(c))
      word[cnt][k++]=tolower(c);
    else if (word[cnt][0]!='\0')
    {
      word[cnt][k]='\0';
      cnt++;k=0;
    }
  }

  qsort(word,cnt,sizeof(word[0]),cmp);

  for (int i=0;i<cnt;i++)
  {
    if (strcmp(word[i],word[i+1]))
      puts(word[i]);
  }


  return 0;
}
