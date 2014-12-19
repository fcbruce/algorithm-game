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
#define sqr(x) (x)*(x)
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int n,t,q1,q2;
int matrix[1001][1001];

void de()
{
         for (int i=0;i<n;i++)
         {
                  for (int j=0;j<n;j++)
                  {

                           printf("%d",matrix[i][j]);
                  }
                  puts("");
         }
         puts("___________________");
}

int cal()
{
         int sum=0;
         for (int i=0;i<n;i++)
         {
                  for (int j=0;j<n;j++)
                  {
                           sum+=(matrix[i][j]*matrix[j][i]);
                  }
         }
         return sum%2;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d",&n);
	for (int i=0;i<n;i++)
         {
                  for (int j=0;j<n;j++)
                  {

                           scanf("%d",&matrix[i][j]);
                  }
         }

	scanf("%d",&t);

	int k=cal();

	for (int i=0;i<t;i++)
         {
                  scanf("%d",&q1);

                  if (q1==3)
                  {
                           printf("%d",k);
                  }

                  if (q1==1)
                  {
                           scanf("%d",&q2);
                           q2--;
/*
                           for (int j=0;j<n;j++)
                           {
                                   matrix[q2][j]=1^matrix[q2][j];
                           }
                           */
                           k=k^1;
                           //de();
                  }

                  if (q1==2)
                  {
                           scanf("%d",&q2);
                           q2--;
/*
                           for (int j=0;j<n;j++)
                           {
                                    matrix[j][q2]=1^matrix[j][q2];
                           }
                           */
                           k=k^1;
                           //de();
                  }


         }

	return 0;
}
