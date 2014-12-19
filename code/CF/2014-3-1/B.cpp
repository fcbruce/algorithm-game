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
	int n;
	char s[100];
	LL a;
	while(~scanf("%d",&n))
         {
                  int b=0;
                  a=0;
                  LL ans=0;
                  LL k=1;
                  scanf("%s",s);
                  for (int i=0;i<n;i++)
                  {
                           if (s[i]=='R')
                           {
                                    a<<=1;
                                    a=a|1;

                           }
                           else
                           {
                                    b++;
                                    a<<=1;
                                    ans+=k;
                           }
                           k<<=1;

                  }
                  printf("%lld\n",ans);
                  /*
                  printf("%lld",a);

                  long long cnt=0;
                  while(b)
                  {
                           cnt++;
                           LL k=0;
                           while (a&(1<<k))
                           {
                                    a=a&(~(1<<k));
                                    k++;
                                    b++;
                           }
                           a=a|(1<<k);
                           b--;
                           printf("%lld!%lld\n",k,a);

                  }
                  printf("%lld\n",cnt);
*/
         }

	return 0;
}
