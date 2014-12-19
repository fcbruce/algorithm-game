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
#define maxm
#define maxn

using namespace std;

class BracketExpressions
{
public:
    bool check(char x,char y)
    {
        if (x=='(' && y==')' || x=='['&& y==']' ||x=='{' && y=='}')
            return true;

        if (x=='X' && (y==']' || y=='}' || y==')' || y=='X')) return true;

        if (y=='X' && (x=='(' || x=='[' || x=='{')) return true;

        return false;
    }
    string ifPossible(string str)
    {
        int l=str.size();

        int dp[60][60];
        memset(dp,0,sizeof dp);
        for(int i = 0; i<l; i++)
        {
            dp[i][i] = 1;
        }

        for (int m=1;m<l;m++)
        {
            for (int i=0;i<l;i++)
            {
                int j=i+m;
                if (j>=l)   break;
                dp[i][j]=INF;
                if (check(str[i],str[j]))
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                for (int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }

        if (dp[0][l-1]==0)  return "possible";
        else
            return "impossible";
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE



    return 0;
}
