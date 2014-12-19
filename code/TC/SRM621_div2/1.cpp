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

bool cmp2(const string &x,const string &y)
{
    return x.length()<y.length();
}

bool cmp1(const string &x,const string &y)
{
    return x<y;
}


class TwoWaysSorting
{
public:
    string sortingMethod(vector <string> stringList);

};

string TwoWaysSorting::sortingMethod(vector <string> stringList)
{
    vector <string> v1(stringList),v2(stringList);
        sort(v1.begin(),v1.end(),cmp1);
        sort(v2.begin(),v2.end(),cmp2);

        if (v1==stringList && v2==stringList)
            return "both";

        if (v1==stringList && v2!=stringList)
            return "lexicographically";

        if (v1!=stringList && v2==stringList)
            return "length";

        if (v1!=stringList && v2!=stringList)
            return "none";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE


    return 0;
}
