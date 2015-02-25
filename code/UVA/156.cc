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
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

map<string,vector<int> >MAP;
map<string,int>OUT;
map<string,vector<int> >::iterator it1;
map<string,int>::iterator it2;
vector<string> vs;
vector<bool> vb;
char s[30];
string temp;


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("t","r",stdin);
  #endif

  while (scanf("%s",s))
  {
    temp=s;
    if (temp=="#")  break;

    vs.push_back(temp);
    vb.push_back(false);
    for (int i=0;i<temp.size();i++)
    {
      s[i]=tolower(s[i]);
    }
    sort(s,s+temp.size());
    temp=s;
    MAP[s].push_back(vs.size()-1);
  }

  for (it1=MAP.begin();it1!=MAP.end();it1++)
  {
    if ((it1->second).size()==1)
      OUT[vs[it1->second[0]]]++;
  }

  for (it2=OUT.begin();it2!=OUT.end();it2++)
  {
    cout<<it2->first<<endl;
  }

  return 0;
}
