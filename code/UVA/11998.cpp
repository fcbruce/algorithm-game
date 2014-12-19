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
#include<list>
#define sqr(x) (x)*(x)
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm 100001

using namespace std;

char s[mm];
list<char> l;
list<char>::iterator it;
bool f=true;
int len;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while(~scanf("%s",s))
         {
                  l.clear();
                  len=strlen(s);
                  it=l.begin();
                  for (int i=0;i<len;i++)
                  {
                           if (s[i]=='[')
                           {
                                    it=l.begin();
                                    continue;
                           }
                           if (s[i]==']')
                           {
                                    it=l.end();
                                    continue;
                           }

                           l.insert(it,s[i]);

                  }

                  for (it=l.begin();it!=l.end();it++)
                  {
                           printf("%c",*it);
                  }
                  puts("");

         }




	return 0;
}
