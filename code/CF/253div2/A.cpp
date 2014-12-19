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

int vis[30];

int main()
{
    #ifndef ONLINE_JUDGE
    //    freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    memset(vis,0,sizeof vis);
    int ans=0;
    char s[10000];
    gets(s);
    int l=strlen(s);
    for (itn i=0;i<l;i++)
    {
        if (islower(s[i]))
        {
            int k=s[i]-'a';
            if (vis[k]==0)
            {
                vis[k]=1;
                ans++;
            }
        }
    }
    printf("%d\n",ans);


    return 0;
}
