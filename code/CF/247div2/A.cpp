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

int c[5];
int a[5];
char s[100001];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d",a+1,a+2,a+3,a+4);
    memset(c,0,sizeof(c));
    scanf("%s",s);
    int l=strlen(s);
    for (int i=0;i<l;i++)
        c[s[i]-'0']++;
    long long sum=0;
    for (int i=1;i<5;i++)
        sum+=(c[i]*a[i]);
    cout<<sum<<endl;

    return 0;
}
