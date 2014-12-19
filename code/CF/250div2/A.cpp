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

char s[4][111];
int l[4];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    //vector<int> v;
    int MAX=-1,MAXL=0,MIN=-1,MINL=INF;
    for (itn i=0;i<4;i++)
    {
        scanf("%s",s[i]);
        l[i]=strlen(s[i])-2;
        if (MAXL<l[i])
        {
            MAX=i;
            MAXL=l[i];
        }
        if (MINL>l[i])
        {
            MINL=l[i];
            MIN=i;
        }
    }
    bool f1=true;bool f2=true;;
    for (int i=0;i<4;i++)
    {
        if (i!=MAX)
        {

            if (MAXL<2*l[i])
            {
                f1=false;
            }
        }
    }

    for (int i=0;i<4;i++)
    {
        if (i!=MIN)
        {

            if (MINL*2>l[i])
            {
                f2=false;
            }
        }
    }

    if (f1&&f2)
    {
        printf("C\n");
        return 0;
    }


    if (f1)
    {
        int cnt=0;
        for (int i=0;i<4;i++)
        {
            if (l[i]==MAXL)
                cnt++;
        }
        if (cnt==1)
        {
            printf("%c\n",'A'+MAX);
        }
        else
        {
            printf("C\n");
        }
        return 0;
    }

    if (f2)
    {
        int cnt=0;
        for (int i=0;i<4;i++)
        {
            if (l[i]==MINL)
                cnt++;
        }
        if (cnt==1)
        {
            printf("%c\n",'A'+MIN);
        }
        else
        {
            printf("C\n");
        }
        return 0;
    }

    if (!f1 && !f2)
    {
        printf("C\n");
    }

    return 0;
}
