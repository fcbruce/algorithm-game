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

struct SumOfPower
{
    int findSum(vector <int> a)
    {
        int n=a.size();
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (j+i<=n)
                for (int k=0;k<i;k++)
                {
                    sum+=a[j+k];
                }
            }
        }
        return sum;
    }

};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
