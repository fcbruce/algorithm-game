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
#define mm 333*16

using namespace std;

int U[mm],D[mm],L[mm],R[mm];
int r[mm],c[mm];
int head,cnt;
int n,m;

inline void init()
{
    U[0]=D[0]=0;
    R[0]=1;L[0]=n;

    for (int i=1;i<=n;i++)
    {
        U[i]=D[i]=i;
        L[i]=i-1;R[i]=i+1;
        c[i]=i;r[i]=0;
    }

    R[n]=0;

    head=0;
    cnt=n;
}

inline void build(int _i)
{
    bool _is_empty=true;
    itn x;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if (x==0)   continue;
        ++cnt;
        if (_is_empty)
        {
            L[cnt]=R[cnt]=cnt;
            _is_empty=false;
        }
        else
        {
            L[cnt]=cnt-1;
            R[cnt]=R[cnt-1];
            L[R[cnt]]=cnt;
            R[L[cnt]]=cnt;
        }

        D[cnt]=i+1;
        U[cnt]=U[i+1];
        D[U[cnt]]=cnt;
        U[D[cnt]]=cnt;

        r[cnt]=_i;
        c[cnt]=i+1;
    }
}

inline void _remove(int _c)
{
    L[R[_c]]=L[_c];
    R[L[_c]]=R[_c];

    for (itn i=D[_c];i!=_c;i=D[i])
    {
        for (int j=R[i];j!=i;j=R[j])
        {
            U[D[j]]=U[j];
            D[U[j]]=D[j];
        }
    }
}

inline void _resume(int _c)
{
    L[R[_c]]=_c;
    R[L[_c]]=_c;

    for (itn i=U[_c];i!=_c;i=U[i])
    {
        for (int j=R[i];j!=i;j=R[j])
        {
            U[D[j]]=j;
            D[U[j]]=j;
        }
    }
}

bool dfs(int k)
{
    int _c=R[head];
    if (head==_c)  return true;

    _remove(_c);

    for (itn i=D[_c];_c!=i;i=D[i])
    {
        for (int j=R[i];j!=i;j=R[j])
            _remove(c[j]);

        if (dfs(k+1))   return true;

        for (itn j=L[i];j!=i;j=L[j])
            _resume(c[j]);
    }


    _resume(_c);

    return  false;

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d%d",&m,&n))
    {
        init();
        for (int i=1;i<=m;i++)
        {
            build(i);
        }

        if (dfs(0))
            puts("Yes, I found it");
        else
            puts("It is impossible");
    }



    return 0;
}
