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

int ans[333];

void build(int x,int pos)
{
    if (x==-1)  return;

    ans[pos]+=x;

    int l,r;

    scanf("%d",&l);
    build(l,pos-1);
    scanf("%d",&r);
    build(r,pos+1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt=1;
    int x;

    while (scanf("%d",&x),~x)
    {
        printf("Case %d:\n",tt++);

        memset(ans,0,sizeof(ans));

        build(x,150);

        int pos;

        for (int i=0;i<333;i++)
        {
            if (ans[i])
            {
                pos=i;
                break;
            }
        }

        printf("%d",ans[pos++]);
        while (ans[pos])
        {
            printf(" %d",ans[pos++]);
        }
        puts("\n");
    }

    return 0;
}
