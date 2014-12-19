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

int a[111111];
int n=0;

bool solve()
{
    stack<int> k,sp;

    for (int i=0;i<n;i++)
    {
        int x=a[i];
        if (x<0)
        {
            if (!k.empty())
            {
                if (sp.top()>abs(x))
                {
                    int t=sp.top();sp.pop();
                    t-=abs(x);
                    sp.push(t);
                }
                else
                {
                    return false;
                }
            }
            k.push(x);sp.push(abs(x));
        }
        else
        {
            if (k.empty())  return false;

            if (x+k.top()!=0)   return false;

            k.pop();sp.pop();
        }
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int x;
    char c;

    while (~scanf("%d%c",&x,&c))
    {
        a[n++]=x;
        if (c=='\n')
        {
            if (n&1)
            {
                puts(":-( Try again.");
                n=0;
                continue;
            }
            if (solve())
            {
                puts(":-) Matrioshka!");
            }
            else
            {
                puts(":-( Try again.");
            }
            n=0;
        }
    }


    return 0;
}
