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
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

char vow[]="AUEOI";
char con[]="JSBKTCLDMVNWFXGPYHQZR";
vector<char> v1;
vector<char> v2;

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

	int tt,c,v,ck,vk;
	int n;
	scanf("%d",&tt);

	for (int t=1;t<=tt;t++)
    {
        v1.clear();
        v2.clear();
        printf("Case %d: ",t);
        scanf("%d",&n);
        c=0;v=0;
        ck=0;vk=0;
        for (int j=0;j<n;j++)
        {
            if (j&1)
            {
                if (c==5)
                {
                    ck++;
                    c=0;
                }
                v1.push_back(con[ck]);
                c++;

            }
            else
            {
                if (v==21)
                {
                    vk++;
                    v=0;
                }
                v2.push_back(vow[vk]);
                v++;
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        c=0;v=0;
        for (int i=0;i<n;i++)
        {
            if (i&1)
            {
                putchar(v1[c++]);

            }
            else
            {
                putchar(v2[v++]);
            }
        }
        puts("");
    }

	return 0;
}
