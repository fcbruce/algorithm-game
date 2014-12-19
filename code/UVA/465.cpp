#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<climits>
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
#define mm 600

using namespace std;
/*
struct bign
{
    int len,s[mm];

    bign()
    {
        memset(s,0,sizeof(s));
        len=1;
    }

    bign(int num)
    {
        *this=num;
    }

    bign(const char *num)
    {
        *this=num;
    }

    bign operator = (int num)
    {
        char s[mm];
        sprintf(s,"%d",num);
        *this=s;
        return *this;
    }

    bign operator =(const char *num)
    {
        len=strlen(num);
        for (int i=0;i<len;i++)
            s[i]=num[len-i-1]-'0';
        return *this;
    }

    bign operator + (const bign& b)const
    {
        bign c;
        c.len=0;
        for (int i=0,g=0;g || i<max(len,b.len);i++)
        {
            int x=g;
            if (i<len)x+=s[i];
            if (i<b.len)x+=b.s[i];
            c.s[c.len++]=x%10;
            g=x/10;
        }
        c.clean();

        return c;
    }

    void clean()
    {
        while (len>1 && !s[len-1])  len--;
    }

    bign operator * (const bign &b)
    {
        bign c;c.len=len+b.len;
        for (int i=0;i<len;i++)
            for (int j=0;j<b.len;j++)
                c.s[i+j]+=s[i]*b.s[j];
        for (int i=0;i<c.len;i++)
        {
            c.s[i+1]+=c.s[i]/10;
            c.s[i]%=10;
        }

        c.clean();
        return c;
    }

    bool operator < (const bign &b)const
    {
        if (len!=b.len) return len<b.len;
        for (int i=len-1;i>=0;i--)
            if (s[i]!=b.s[i])   return s[i]<b.s[i];

        return false;
    }
};
*/

const int maxn = 600;
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

	char s1[mm],s2[mm],ans[mm];
	char op;
	bign a,b,c,d;
	d=2147483647;
	//double a,b,c,d=INT_MAX;


	while (~scanf("%s %c %s",s1,&op,s2))
    {
        //a=atof(s1);b=atof(s2);
        a=s1;b=s2;
        //cout<<a<<' '<<op<<' '<<b<<endl;
        a.clean();b.clean();

        printf("%s %c %s\n",s1,op,s2);

        if (a>d)puts("first number too big");

        if (b>d)puts("second number too big");

        if (op=='+')
        {
            c=a+b;
            if (c>d)puts("result too big");
            continue;
        }
        if (op=='*')
        {
            c=a*b;
            if (c>d)puts("result too big");
            continue;
        }

        while (1)
        {
            ;
        }

    }

	return 0;
}
