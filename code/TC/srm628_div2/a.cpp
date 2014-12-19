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

class BishopMove
{
public:
    int howManyMoves(int r1, int c1, int r2, int c2)
    {
        if (r1==r2 && c1==c2)   return 0;
        if (((r1+c1)&1) == ((r2+c2)&1))
        {
            if (abs(r1-r2)==abs(c1-c2)) return 1;

            return 2;
        }


        return -1;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
