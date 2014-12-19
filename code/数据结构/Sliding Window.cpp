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
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm 1000007

using namespace std;

itn k,n;
int a[mm];
int q[mm];
int f,r;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d%d",&n,&k))
    {
        for (itn i=0;i<n;i++)
            scanf("%d",a+i);
        //min
        f=0;r=-1;
        for (int i=0;i<k-1;i++)
        {
            while (f<=r && a[q[r]]>a[i])
                r--;
            q[++r]=i;
        }
        for (int i=k-1;i<n;i++)
        {
            while (f<=r && a[q[r]]>a[i])
                r--;
            q[++r]=i;
            while (q[f]<i-k+1)  f++;
            printf("%d",a[q[f]]);
            if (i!=n-1) putchar(' ');
        }
        puts("");


        //max
        f=0;r=-1;
        for (int i=0;i<k-1;i++)
        {
            while (f<=r && a[q[r]]<a[i])
                r--;
            q[++r]=i;
        }
        for (int i=k-1;i<n;i++)
        {
            while (f<=r && a[q[r]]<a[i])
                r--;
            q[++r]=i;
            while (q[f]<i-k+1)  f++;
            printf("%d",a[q[f]]);
            if (i!=n-1) putchar(' ');
        }
        puts("");
    }


    return 0;
}
