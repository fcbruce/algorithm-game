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
#define maxm
#define maxn 123456

using namespace std;

itn n;
int a[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d",&n);

    for (int i=0;i<n;i++)
        scanf("%d",a+i);

    if (n==2)
    {
        if (a[0]>a[1])cout<<1<<endl;
        else    cout<<0<<endl;

        return 0;
    }

    int cnt=0;
    int MIN1=a[0],k=-1;
    for (int i=1;i<n;i++)
    {
        if (a[i]<a[i-1])   { k=i;break;}
    }

    int k2=-1;
    for (int i=k+1;i<n;i++)
    {
        if (a[i]<a[i-1])
        {
            k2=i;break;
        }
    }

    if (k==-1)
    {
        printf("%d\n",0);
        return 0;
    }

    if (k2==-1)
    {
        if (a[n-1]<=a[0])
        {
            printf("%d\n",n-k);
            return 0;
        }
        else
        {
            puts("-1");
            return 0;
        }
    }

    puts("-1");




    return 0;
}
