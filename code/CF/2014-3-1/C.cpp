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
#define mm 200005

using namespace std;

char s[mm];


int main()
{
         LL a,b;
         while (scanf("%lld%lld",&a,&b)==2)
         {
                  if (b>a)
                  {
                         int k=b/(a+1);
                         int m=b%(a+1);
                         LL ans=sqr(k+1)*m+sqr(k)*(a+1-m);
                         printf("%lld\n",a-  ans);
                         for (int i=0;i<m;i++)
                         {
                                  for (int j=0;j<k+1;j++)
                                             printf("x");
                                    printf("o");
                         }
                         for (int i=0;i<(a-m);i++)
                         {
                                  for (int j=0;j<k;j++)
                                  {
                                           printf("x");
                                  }
                                  printf("o");
                         }
                         for (int j=0;j<k;j++)
                           {
                                    printf("x");
                           }

                  }
                  else
                  {
                           if (b<=2)
                           {
                                    printf("%lld\n",a*a-b);
                                    if (b) {printf("x");b--;}
                                    while (a--)       printf("o");
                                    if (b) {printf("x");b--;}
                                    continue;
                           }
                           if (a)
                           {
                                    printf("%lld\n",sqr(a)-sqr(b/2)-sqr(b-b/2));
                                    for (int i=0;i<b/2;i++)
                                             printf("x");
                                    for (int i=0;i<a;i++)
                                    {

                                             printf("o");
                                    }
                                    for (int i=0;i<b-b/2;i++)
                                             printf("#");
                              //      puts(s1.c_str());
                              continue;

                           }
                           b-=2;
                           string ss;
                           sprintf(s,"x");
                           ss=s;
                           while (a&&b)
                           {
                                    sprintf(s,"ox");
                                    ss+=s;
                                    a--;
                                    b--;
                           }
                           printf("%lld\n",a*a-2);
                           while(a)
                           {
                                    sprintf(s,"o");
                                    ss+=s;
                                    a--;
                           }
                           ss+="x";
                           puts(ss.c_str());
                  //         cout<<ss.size()<<endl;
                  }
         }


    return 0;
}
