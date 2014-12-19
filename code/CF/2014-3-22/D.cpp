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
#define mm 1000001
#define s 1000000

using namespace std;

bool vis[mm];
int a[mm];
int x,l,r,n,cnt=0;
LL sum;

void dfs(int sum)
{
         if (!vis[s-sum])
         {
                  a[cnt++]=s-sum;
                  sort(a,a+cnt);
                  printf("%d\n",cnt);
                  for (int i=0;i<cnt;i++)
                  {
                           printf("%d ",a[i]);
                  }
                  exit(0);
         }
         else
         {
                  int i;
                  for (i=s-sum+1;vis[i] && i<mm;i++);
                  if (i==mm)
                           return ;
                  a[cnt++]=i;
                  sum=sum-(s-i);
                  dfs(sum);
         }
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	memset(vis,false,sizeof(vis));
	scanf("%d",&n);

	for (int i=0;i<n;i++)
         {
                  scanf("%d",&x);
                  sum+=(x-1);
                  vis[x]=true;
         }

         if (sum==0)
         {
                  printf("%d\n%d\n",1,s);
                  return 0;
         }

         dfs(sum);


	return 0;
}
