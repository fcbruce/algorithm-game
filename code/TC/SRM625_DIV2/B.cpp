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

class IncrementingSequence
{
public:
    string canItBeDone(int k, vector <int> A)
    {
        int n=A.size();
        int vis[55];
        memset(vis,0,sizeof vis);
        sort(A.begin(),A.end());
        for (itn i=0;i<n;i++)
        {
            if (A[i]>n) return "IMPOSSIBLE";
            if (A[i]>0) vis[A[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (vis[A[i]]>1)
            {
                vis[A[i]]--;
                while (A[i]+k<=n && vis[A[i]+k]!=0)  A[i]+=k;

                if (vis[A[i]+k]==0)
                {
                    vis[A[i]+k]=1;
                    A[i]+=k;
                }
                else
                {
                    return "IMPOSSIBLE";
                }
            }
        }
        for (int i=1;i<=n;i++)
            if (vis[i]!=1)  return "IMPOSSIBLE";

        return "POSSIBLE";
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
