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

class NumbersChallenge
{
public:
    int MinNumber(vector <int> S);
};

int NumbersChallenge::MinNumber(vector <int> S)
{
    sort(S.begin(),S.end());
/*
    int sum=0;
    for (int i=0;i<S.size();i++)
    {
        if (sum+1<S[i])
            break;
        else
            sum+=S[i];
    }
    return sum+1;
    */
    int sum=1;
    for (int i=0;i<S.size();i++)
    {
        if (sum<S[i])
            return sum;
        else
            sum+=S[i];
    }
    return sum;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE
    vector <int> v;
NumbersChallenge t;
    v.push_back(1);
    cout<<t.MinNumber(v)<<endl;


    return 0;
}
