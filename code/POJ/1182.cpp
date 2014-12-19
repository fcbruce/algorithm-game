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
#define mm 50005

using namespace std;

int a[mm*3];

void init()
{
         for (int i=0;i<mm*3;i++)
         {
                  a[i]=i;
         }
}

int root(int x)
{
         if (a[x]==x)
                  return x;

         return a[x]=root(a[x]);
}

bool same(int x,int y)
{
         int rx=root(x);
         int ry=root(y);

         if (rx==ry)
                  return true;

         return false;
}

void intree(int x,int y)
{
         int rx=root(x);
         int ry=root(y);

         if (rx==ry)
                  return ;

         a[ry]=rx;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int k,n,ans=0;
	int d,x,y;

	scanf("%d%d",&n,&k);

         ans=0;
         init();

         for (int i=0;i<k;i++)
         {
                  scanf("%d%d%d",&d,&x,&y);
                  if (x<1 || x>n || y<1 || y>n)//判断下标是否符合要求
                  {
                           ans++;
                           continue;
                  }

                  if (d==1)
                  {
                           if (same(x,y+mm) || same(x,y+mm*2))//same(x,y+mm)判断是否x吃y，same(x,y+mm*2)判断是否y吃x
                           {
                                    ans++;
                           }
                           else
                           {
                                    intree(x,y);
                                    intree(x+mm,y+mm);
                                    intree(x+mm*2,y+mm*2);
                           }
                  }
                  else
                  {
                           if (same(x,y) || same(x,y+mm*2))//same(x,y)判断是否x，y同类，same(x,y+mm*2)判断是否y吃x
                           {
                                    ans++;
                           }
                           else
                           {
                                    intree(x,y+mm);
                                    intree(x+mm,y+mm*2);
                                    intree(x+mm*2,y);
                           }
                  }
         }

         printf("%d\n",ans);

	return 0;
}
