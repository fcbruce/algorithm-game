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
#define maxn 1234567

using namespace std;

struct nn
{
    itn a,b;
    bool operator <(const nn &n)const
    {
        return a<n.a;
    }
}x[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    itn n;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&x[i].a,&x[i].b);

    }

    sort(x,x+n);

//    int bb=x[0].b;
    for (int i=1;i<n;i++)
    {
//        printf("%d %d\n",x[i].b,x[i-1].b);
        if (x[i].b<x[i-1].b)
        {
            printf("Happy Alex\n");
            return 0;
        }
    }

    puts("Poor Alex");

    return 0;
}
