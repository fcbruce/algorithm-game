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

int a[257][11];

int main()
{
    #ifndef ONLINE_JUDGE
     //   freopen("/home/fcbruce/文档/code/t","r",stdin);
    //    freopen("/home/fcbruce/文档/code/t1","w",stdout);
    #endif // ONLINE_JUDGE

    int x=1;
    memset(a,0,sizeof(a));
    for (int i=1;i<=256;i++)
    {

        for (int j=i+1;j<=i*2;j++){
            int k=j,c=0;
            while (k)
            {
                if (k&1)
                    c++;
                k>>=1;
            }
            a[i][c]++;
        }
    }

    LL m,k;


    long long l=1,r=1000000000000000000LL,mid;
    cin>>m>>k;
    while (l<=r)
    {
        mid=(l+r)>>1;
        LL t=mid;
        LL x=k/8;
        cout<<x<<endl;

       t=t/(256LL*x);

       x=k-(8*x)+1;

       printf("%lld %lld\n",t,x);

       if (a[t][x]==m)
       {
           cout<<mid<<endl;
           return 0;
       }

       if (a[t][x]>m)
       {
           r=mid-1;
       }
       else
       {

           l=mid+1;
       }


    }



    return 0;
}
