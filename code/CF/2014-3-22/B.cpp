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
#define sqr(x) (x)*(x)
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int n;
char s[3333];
int ans=0;
int temp=0;//当前区间内暂时竖直的骨牌数量
bool R;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d%s",&n,s);
	R=false;
	for (int i=0;i<n;i++)
	{
	         if (s[i]=='.')
                  {
                           temp++;
                  }
                  else
                  {
                           if (s[i]=='L')
                           {
                                    if (R)
                                    {
                                             ans+=(temp%2);
                                             temp=0;
                                    }
                                    else
                                    {
                                             temp=0;
                                    }
                                    R=false;
                           }
                           else
                           {
                                    ans+=temp;
                                    temp=0;
                                    R=true;
                           }
                  }

	}
	if (!R)
                  ans+=temp;        //见第二个样例

	printf("%d\n",ans);

	return 0;
}
