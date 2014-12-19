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
#define mm 100007

using namespace std;

int a[mm];
struct Node
{
    int v,l,r,p,s;
    void _set(int _v,itn _l,itn _r,int _p,int _s)
    {
        v=_v;l=_l;r=_r;p=_p;s=_s;
    }
}s[mm];
vetcor<itn> v[mm];
map<int,int>MAP;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d %d",&n,&m))
    {
        MAP.clear();
        int _v=-1,_p,_l,_r,_s;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            if (_v!=a[i])
            {
                if (MAP[_v])
                    _id=MAP[_v];
                else
                    _id=MAP[_v]=_cnt++;


                s[cnt++]._set(_v,_l,_r,_p,_s);
            }
        }
    }

    return 0;
}
