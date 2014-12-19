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

class AddMultiply
{
public:
    vector <int> makeExpression(int y)
    {
        int r=sqrt(y);
        vector <int> res;
        while (r==0 || r==1 || y-r*r==1 || y-r*r==0)
        {
            r--;
        }
        res.push_back(r);
        res.push_back(r);
        res.push_back(y-r*r);
        return res;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
