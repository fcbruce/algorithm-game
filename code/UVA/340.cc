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
#define mm 1001

using namespace std;

int STD[mm];
int vis[mm],a[mm],s,w;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n,tt=0;

	while (scanf("%d",&n),n)
    {
        printf("Game %d:\n",++tt);
        for (int i=0;i<n;i++)
        {
            scanf("%d",STD+i);
        }

        while (1)
        {
            for (int i=0;i<n;i++)
                scanf("%d",a+i);
            if (a[0]==0)    break;
            s=w=0;
            memset(vis,0,sizeof(vis));
            for (int i=0;i<n;i++)
            {
                if (a[i]==STD[i])
                {
                    s++;
                    vis[i]=1;
                }
            }
            for (int i=0;i<n;i++)
            {
                if (a[i]!=STD[i])
                {
                    for (int j=0;j<n;j++)
                    {
                        if (!vis[j] && a[i]==STD[j])
                        {
                            w++;
                            vis[j]=1;
                            break;
                        }
                    }
                }
            }

            printf("    (%d,%d)\n",s,w);
        }
    }


	return 0;
}
