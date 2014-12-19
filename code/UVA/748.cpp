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

const int maxn = 200;
struct bign{
  int len, s[maxn];

  bign() {
    memset(s, 0, sizeof(s));
    len = 1;
  }

  bign(int num) {
    *this = num;
  }

  bign(const char* num) {
    *this = num;
  }

  bign operator = (int num) {
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
  }

  bign operator = (const char* num) {
    len = strlen(num);
    for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
    return *this;
  }

  string str() const {
    string res = "";
    for(int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
    if(res == "") res = "0";
    return res;
  }

  bign operator + (const bign& b) const{
    bign c;
    c.len = 0;
    for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
      int x = g;
      if(i < len) x += s[i];
      if(i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      g = x / 10;
    }
    return c;
  }

  void clean() {
    while(len > 1 && !s[len-1]) len--;
  }

  bign operator * (const bign& b) {
    bign c; c.len = len + b.len;
    for(int i = 0; i < len; i++)
      for(int j = 0; j < b.len; j++)
        c.s[i+j] += s[i] * b.s[j];
    for(int i = 0; i < c.len-1; i++){
      c.s[i+1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }

  bign operator - (const bign& b) {
    bign c; c.len = 0;
    for(int i = 0, g = 0; i < len; i++) {
      int x = s[i] - g;
      if(i < b.len) x -= b.s[i];
      if(x >= 0) g = 0;
      else {
        g = 1;
        x += 10;
      }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }

  bool operator < (const bign& b) const{
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(s[i] != b.s[i]) return s[i] < b.s[i];
    return false;
  }

  bool operator > (const bign& b) const{
    return b < *this;
  }

  bool operator <= (const bign& b) {
    return !(b > *this);
  }

  bool operator == (const bign& b) {
    return !(b < *this) && !(*this < b);
  }

  bign operator += (const bign& b) {
    *this = *this + b;
    return *this;
  }
};

istream& operator >> (istream &in, bign& x) {
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator << (ostream &out, const bign& x) {
  out << x.str();
  return out;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int l,n,m;
	char *p;
	double x;
	bign a,b;
	char s[100];

	while (~scanf("%s %d",s,&n))
    {
        l=strlen(s);
        while (s[l-1]=='0') {s[l-1]='\0';l--;}
        p=strchr(s,'.');
        p++;
        x=atof(s);
        m=0;
        for (;*p;p++,m++)   x*=10;
        a=(int)x;
        sprintf(s,"%.f",x);
        a=s;
        //cout<<a<<endl;
        b=1;
        for (int i=0;i<n;i++)
        {
            b=b*a;
        }
        b.clean();
       // cout<<b<<endl;
       // printf("n*m=%d len=%d\n",n*m,b.len);
        if ((m*n)>b.len)
        {
            printf(".");
            for (int i=m*n;i>b.len;i--)
            {
                printf("0");
            }
        }
        for (int i=b.len-1;i>=0;i--)
        {
            if ((n*m-1)==i)   printf(".");
            printf("%d",b.s[i]);
        }

        puts("");



    }


	return 0;
}
