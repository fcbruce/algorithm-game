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

class MixingColors
{
public:

    int minColors(vector <int> a);
};

int MixingColors::minColors(vector <int> a)
{
    bool bit[33];
    memset(bit,false,sizeof(bit));
    for (int i=0;i<a.size();i++)
    {
        int n=0;
        while (a[i])
        {
            if (a[i]&1)
                bit[n]=true;

            a[i]>>=1;
            n++;
        }


    }

    int cnt=0;
     for (int i=0;i<33;i++)
            if (bit[i]) cnt++;

        return min(cnt,a.size());
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE
vector <int> v;
    for (int i=1;i<16;i++)
        v.push_back(i);
    MixingColors m;

    cout<<m.minColors(v)<<endl;;

    return 0;
}
