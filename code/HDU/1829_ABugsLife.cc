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

using namespace std;

int pre[mm<<1];
int vis[mm];
bool flag;

void init()
{
         for (int i=0;i<(mm<<1);i++)
         {
                  pre[i]=i;
         }

         memset(vis,0,sizeof(vis));

}

int root(int x)
{
         if (pre[x]==x)
         {
                  return x;
         }

         return pre[x]=root(pre[x]);
}

void intree(int x,int y)
{
         int rx=root(x);
         int ry=root(y);

         if (rx==ry)
         {
                  flag=false;
                  return ;
         }

         int rx2=root(x+mm);
         int ry2=root(y+mm);

         pre[rx]=ry2;
         pre[ry]=rx2;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t","r",stdin);
    #endif

    int tt,n,m,x,y;
    scanf("%d",&tt);

    for (int t=0;t<tt;t++)
         {
                  init();
                  int cnt=0;


                  flag=true;

                  printf("Scenario #%d:\n",t+1);

                  scanf("%d%d",&n,&m);

                  for (int i=0;i<m;i++)
                  {
                           scanf("%d%d",&x,&y);
                           if (flag)
                           {

                                    intree(x,y);
                           }
                  }

                  if (flag)
                  {
                           puts("No suspicious bugs found!");
                  }
                  else
                  {
                           puts("Suspicious bugs found!");
                  }
                  puts("");
         }


    return 0;
}
