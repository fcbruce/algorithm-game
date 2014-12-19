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
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

int a[30];
int n,k,m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d%d%d",&n,&k,&m),n||k||m)
    {
        int rest=n;
        bool f=false;
        memset(a,-1,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            a[i]=1;
        }
        int l=0,r=n+1;
        while (rest)
        {
            for  (int i=1;i<=k;i++)
            {
                while (a[l]==-1)
                {
                    l++;
                    if (l==n+1)   l=0;
                }
                if (i==k)   break;
                l++;
                if (l==n+1)   l=0;
            }
            for  (int i=1;i<=m;i++)
            {
                while (a[r]==-1)
                {
                    r--;
                    if (r==0)   r=n+1;
                }
                if (i==m)   break;
                r--;
                if (r==0)   r=n+1;
            }

            if (f)  printf(",");
            f=true;

            if (r==l)
            {
                a[r]=-1;
                printf("%3d",r);
                rest--;
            }
            else
            {
                a[l]=a[r]=-1;
                printf("%3d%3d",l,r);
                rest-=2;
            }
        }
        printf("\n");

    }

    return 0;
}
