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
#define maxn

using namespace std;

struct SquareDivisor
{
    long long biggest(long long n)
    {
//        long long ans=1;
//        for (long long  i=2;n!=1 && i<=(long long)sqrt(n);i++)
//        {
//            int cal=0;
//            while ((n%i)==0)
//            {
//                cal++;
//                n/=i;
//                if ((cal&1)==0)
//                    ans*=i;
//            }
//        }

        for (LL i=2;sqr((long long)sqrt(n))!=n;i++)
        {
            while (sqr((long long)sqrt(n))!=n && (n%i)==0)
            {

                n/=i;

            }
        }

        return n;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
