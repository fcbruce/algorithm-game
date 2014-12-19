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

set<string> ignore;
multimap<string,string>MAP;
string str;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (getline(cin,str)&&str!="::")
        ignore.insert(str);

    while (getline(cin,str))
    {
        for (int i=0;i<str.size();i++)
            str[i]=tolower(str[i]);

        for (int i=0;i<str.size();i++)
        {
            if (!isalpha(str[i]))   continue;

            string t;
            int j=i;
            while (isalpha(str[j]))
                t+=str[j++];

            if (!ignore.count(t))
            {
                for (int k=0;k<t.size();k++)
                    t[k]=toupper(t[k]);
                string tt=str;
                tt.replace(i,t.size(),t);
                MAP.insert(make_pair(t,tt));
            }
            i=j;
        }
    }

    for (map<string,string>::iterator it=MAP.begin();it!=MAP.end();it++)
    {
        cout<<it->second<<endl;
    }



	return 0;
}
