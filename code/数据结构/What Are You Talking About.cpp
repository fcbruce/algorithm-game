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

map<string,string> dict;
string _read;
char _write[3333];
char s1[20],s2[20];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%s",s1);
    string t1,t2;
    while (scanf("%s",s1),strcmp(s1,"END"))
    {
        scanf("%s",s2);
        t1=s1;t2=s2;
        dict[t2]=t1;
    //    printf("%s %s\n",t2.c_str(),t1.c_str());
    }
    scanf("%s",s1);getchar();
    t1="";
    char ch;
    while (true)
    {
        while (ch=getchar(),isalpha(ch))
        {
            t1+=ch;
        }

        if (t1=="END")  break;

     //   printf("%s",t1.c_str());

        if (dict.count(t1))
        {
            printf("%s",dict[t1].c_str());
        }
        else
        {
            printf("%s",t1.c_str());
        }

        t1="";

        putchar(ch);
    }

    return 0;
}
