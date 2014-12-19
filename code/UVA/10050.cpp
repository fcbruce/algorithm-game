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
#include<list>
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

bool a[4000];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);

    while (tt--)
    {
        int n,p;
        int cnt=0;
        memset(a,false,sizeof(a));
        scanf("%d",&n);
        scanf("%d",&p);
        for (int i=0;i<p;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=x;j<=n;j+=x)
            {
                a[j]=true;
            }
        }
        for (int i=6;i<=n;i+=7)
        {
            a[i]=a[i+1]=false;
        }
        for (int i=1;i<=n;i++)
        {
            if (a[i])   cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
