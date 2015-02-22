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

int alp[27];

char str1[1111],str2[1111];
int cnt,total,error;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/fcbruce/code/t","r",stdin);
#endif

	int r;

	while (scanf("%d",&r)&&(~r))
  {
    scanf("%s%s",str1,str2);

    cnt=total=error=0;

    int l1=strlen(str1),l2=strlen(str2);

    memset(alp,0,sizeof(alp));

    for (int i=0;i<l1;i++)
    {
      if (alp[str1[i]-'a']==0)
      {
        total++;
        alp[str1[i]-'a']=1;
      }
    }

    for (int i=0;i<l2;i++)
    {
      if (alp[str2[i]-'a']==-1)
        continue;

      if (alp[str2[i]-'a']==1)
      {
        alp[str2[i]-'a']=-1;
        cnt++;
        if (cnt==total)
          break;
      }
      else
      {
        error++;
        if (error==7) break;
      }
    }

    printf("Round %d\n",r);
    if (error==7)
    {
      puts("You lose.");
    }
    else
    {
      if (cnt==total)
        puts("You win.");
      else
        puts("You chickened out.");
    }


  }


	return 0;
}
