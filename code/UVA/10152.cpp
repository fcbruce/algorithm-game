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

char a[222][222],b[222][222];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;

    scanf("%d",&tt);

    while (tt--)
    {
        scanf("%d",&n);getchar();
        for (int i=0;i<n;i++)
        {
            fgets(a[i],222,stdin);
            int k=0;
            while (a[i][k]!='\n')   k++;
            a[i][k]='\0';
        }

        for (int i=0;i<n;i++)
        {
            fgets(b[i],222,stdin);
            int k=0;
            while (b[i][k]!='\n')   k++;
            b[i][k]='\0';
        }
        int j=n-1;
        for  (int i=n-1;i>=0;i--)
        {
            if (strcmp(a[i],b[j])==0)   j--;
            else
            {

            }
        }
        for (;j>=0;j--)
            puts(b[j]);
        puts("");
    }


    return 0;
}
