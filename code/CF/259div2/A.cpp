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
#define maxn 111

using namespace std;

char a[maxn][maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%d",&n);

    memset(a,'D',sizeof a);
    int k=n/2;
    for (int i=1;i<=n/2;i++)
    {
        for (int j=1;j<=k;j++)
            a[i][j]='*';

        for (int j=n;j>n-k;j--)
            a[i][j]='*';

        k--;
    }

    k=1;

    for (itn i=n/2+2;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
            a[i][j]='*';

        for (int j=n;j>n-k;j--)
            a[i][j]='*';

        k++;
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            putchar(a[i][j]);
        puts("");
    }






    return 0;
}
