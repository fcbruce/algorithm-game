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

struct pp
{
    int x,y;
}p[105];
itn n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d",&n),n)
    {
        for (int i=0;i<(n<<1);i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        bool flag=true;
        for (int i=-500;i<501 && flag;i++)
        {
            for (int j=-500;j<501 && flag;j++)
            {
                int cnt=0;
                itn k;
                for (k=0;k<n<<1;k++)
                {
                    if (i*p[k].x+j*p[k].y==0)   break;
                    if (i*p[k].x+j*p[k].y>0) cnt++;
                }

                if (cnt==n && k==(n<<1))
                {
                    flag=false;
                    printf("%d %d\n",i,j);
                }
            }
        }
//        int l=-500,r=500;
//        int ans=0;
//
//        while (l<r)
//        {
//            int mid=(l+r)>>1;
//            int cnt=0;
//
//            for (int i=0;i<(n<<1);i++)
//            {
//                long long y=mid*p[i].x;
//                if (y<p[i].y) cnt++;
//            }
//
//            if (cnt==n)
//            {
//                ans=mid;
//                break;
//            }
//
//            if (cnt>n)
//            {
//                l=mid+1;
//            }
//            else
//            {
//                r=mid-1;
//            }
//        }
//
//        printf("%d %d\n",ans,-1);
    }

    return 0;
}
