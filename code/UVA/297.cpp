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

bool black[2000];
char t[3000];
int l,n,k;
//l 字符串长度, n 当前染色位置, k 当前字符

void solve(int RANK)
{
    if (k==l)   return ;

    if (t[k]=='f')
    {
        k++;
        for (int i=0;i<RANK;i++)
        {
            black[n++]=true;
        }
        return;
    }
    if (t[k]=='e')
    {
        k++;
        n+=RANK;
        return;
    }
    if (t[k]=='p')
    {
        k++;
        for (int i=0;i<4;i++)
        {
            solve(RANK/4);
        }
        return;
    }

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
        memset(black,false,sizeof(black));
        scanf("%s",t);
        l=strlen(t);
        n=k=0;
        solve(1024);
        scanf("%s",t);
        l=strlen(t);
        n=k=0;
        solve(1024);
        int ans=0;
        for (int i=0;i<1024;i++)
        {
            if (black[i])   ans++;
        }
        printf("There are %d black pixels.\n",ans);
    }

    return 0;
}
