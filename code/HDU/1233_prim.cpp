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

int n;
int g[111][111];
int mincost[111];
bool used[111];

int prim()
{
         memset(mincost,0x3f,sizeof(mincost));
         memset(used,false,sizeof(used));

         mincost[1]=0;
         int ans=0;

         while(true)
         {
                  int v=-1;

                  for (int i=1;i<=n;i++)
                  {
                           if (!used[i] && (v==-1 || mincost[i]<mincost[v]))
                           {
                                    v=i;
                           }
                  }

                  if (v==-1)  break;

                  used[v]=true;

                  ans+=mincost[v];

                  for (int i=1;i<=n;i++)
                  {
                           mincost[i]=min(mincost[i],g[v][i]);
                  }
         }

         return ans;

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int x,y,d;

	while (scanf("%d",&n)&&n)
         {
                  memset(g,0x3f,sizeof(g));

                  int t=n*(n-1)/2;

                  for (int i=0;i<t;i++)
                  {
                           scanf("%d%d%d",&x,&y,&d);
                           g[x][y]=g[y][x]=d;
                  }

                  printf("%d\n",prim());
         }

	return 0;
}
