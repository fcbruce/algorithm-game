#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define sqr(x) (x)*(x)
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define LL long long
#define mm

using namespace std;

int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	int be=max(p-k,1);
	int en=min(p+k,n);

	if (be>1)
         {

                  printf("<< ");
         }
	for (int i=be;i<=en;i++)
         {
                  if (i==p)
                  {
                           printf("(%d) ",i);
                  }
                  else{
                           printf("%d ",i);
                  }
         }
	if (en<n)
         {

                  printf(">>");
         }
	return 0;
}
