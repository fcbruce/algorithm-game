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
#define mm 5005

using namespace std;

int n;
int t;
int a[111];

struct edge
{
         int u,v,d;
}es[mm];

bool cmp(const edge &x,const edge &y)
{
         return x.d<y.d;
}

void init()
{
         for (int i=0;i<111;i++)
         {
                  a[i]=i;
         }
}

int root(int x)
{
         if (x==a[x])
                  return x;

         return a[x]=root(a[x]);
}

bool same(int x,int y)
{
         int rx=root(x);
         int ry=root(y);

         return rx==ry;
}

void intree(int x,int y)
{
         int rx=root(x);
         int ry=root(y);

         a[ry]=rx;
}

int kruskal()
{
         init();

         int ans=0;

         for (int i=0;i<t;i++)
         {
                  if (!same(es[i].u,es[i].v))
                  {
                           intree(es[i].u,es[i].v);

                           ans+=es[i].d;
                  }
         }

         return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while(scanf("%d",&n)&&n)
         {
                  t=n*(n-1)/2;

                  for (int i=0;i<t;i++)
                  {
                           scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].d);
                  }

                  sort(es,es+t,cmp);

                  printf("%d\n",kruskal());
         }


	return 0;
}
