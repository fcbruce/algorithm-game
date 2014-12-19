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
#define mm

using namespace std;

int a[20][333];
int status[333];
itn n,m;

bool dfs(int x)
{
    if (x==m)    return false;

//    printf("%d\n",x);

    bool flag1=true;
    bool flag2=true;

    for (int i=0;i<n;i++)
    {
        if (a[x][i])    status[i]++;
        if (status[i]!=1)   flag1=false;
        if (status[i]>1)    flag2=false;
    }

//    for (int i=0;i<n;i++)
//        printf("%d ",status[i]);
//    puts("");

    if (flag1)   return true;

    if (flag2)  if (dfs(x+1)) return true;

    for (int i=0;i<n;i++)
        if (a[x][i])    status[i]--;

    if (dfs(x+1)) return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d%d",&m,&n))
    {
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                scanf("%d",*(a+i)+j);

        memset(status,0,sizeof status);

        if (dfs(0))
            puts("Yes, I found it");
        else
            puts("It is impossible");

    }

    return 0;
}
