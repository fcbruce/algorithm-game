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

string s;
int a[100];

class ConundrumReloaded
{
public:
    int minimumLiars(string answer)
    {
        s=answer;
        int n=s.size();
        int MIN=INF;

        memset(a,-1,sizeof (a));
        int res=0;
        a[0]=1;//T
        int i=0;
        while (i<n)
        {
            if (s[i]=='?')  {i++;continue;}
            if (s[i]=='H')
            {
                if (a[i])   a[(i+1)%n]=1;
                else        {a[(i+1)%n]=0;res++;}
            }
            else
            {
                if (a[i])   {a[(i+1)%n]=0;res++;}
                else        a[(i+1)%n]=1;
            }
            i++;
        }

        if (a[0]==1) MIN=res;

        a[0]=0;
        res=0;
        i=0;
        while (i<n)
        {
            if (s[i]=='?')  {i++;continue;}
            if (s[i]=='H')
            {
                if (a[i])   a[(i+1)%n]=1;
                else        {a[(i+1)%n]=0;res++;}
            }
            else
            {
                if (a[i])   {a[(i+1)%n]=0;res++;}
                else        a[(i+1)%n]=1;
            }
            i++;
        }
        if (a[0]==0)    MIN=min(MIN,res);

        if (MIN==INF)   return -1;
        else    return MIN;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
