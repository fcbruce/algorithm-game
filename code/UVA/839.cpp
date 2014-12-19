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

bool balance;

int tree()
{
    int w1,d1,w2,d2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);

    if (w1==0)
    {
        w1=tree();
    }

    if (w2==0)
    {
        w2=tree();
    }

    if (w1*d1!=w2*d2)   balance=false;

    return w1+w2;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);

    while (tt--)
    {
        balance=true;
        tree();
        if (balance)
            puts("YES");
        else
            puts("NO");
        if (tt) puts("");
    }


    return 0;
}
