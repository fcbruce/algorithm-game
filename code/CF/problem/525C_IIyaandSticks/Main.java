/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 29 Mar 2015 02:25:01 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Solve solver = new Solve();
    solver.run(in,out);
    out.close();
  }
}

class Solve {
  class stick
  {
    int l,cnt1,cnt2;

    stick (int a,int b,int c) {
      l=a;
      cnt1=b;
      cnt2=c;
    }

    void sub(int c) {
      if (c<cnt2) {
        cnt2-=c;
        return ;
      }
      c-=cnt2;
      cnt2=0;
      cnt1-=c;
    }

    boolean ok() {
      return (cnt1+cnt2)%2==1 && cnt1>0;
    }

    int compareTo(stick o) {
      return l-o.l;
    }

    void prt() {
      System.out.println(l+" "+cnt1+" "+cnt2);
    }
  }

  public void run(InputReader in,PrintWriter out) {

    int n=in.nextInt();
    int []a=new int [n];
    for (int i=0;i<n;i++) a[i]=in.nextInt();
    Arrays.sort(a);
    stick []s=new stick[n];
    int cnt=0;
    for (int i=0;i<n;i++) {
      if (i>0 && a[i]==a[i-1]) s[cnt-1].cnt1++;
      else s[cnt++]=new stick(a[i],1,0);
    }


    long area=0;

    for (int i=cnt-1,j=i;i>=0;i--) {
      if (j>=0 && s[i].ok() && s[i].l-1==s[j].l) {
        s[i].cnt1--;
        s[j].cnt2++;
      }

      if (i==j) {
        int c=s[i].cnt1+s[i].cnt2>>2;
        area+=(long )s[i].l*s[i].l*c;
        s[i].sub(c<<2);
        if (j>0) {
          if (s[j].ok() && s[j].l-1==s[j-1].l) {
            s[j].cnt1--;
            s[j-1].cnt2++;
          }
          j--;
        }
      }

      while (i!=j && s[i].cnt1+s[i].cnt2>1 && j>=0) {
        int c=Math.min(s[i].cnt1+s[i].cnt2>>1,s[j].cnt1+s[j].cnt2>>1);

        area+=(long )s[i].l*s[j].l*c;

        s[i].sub(c<<1);
        s[j].sub(c<<1);
        
        if (s[j].cnt1+s[j].cnt2<=1) {
          if (j>0 && s[j].ok() && s[j].l-1==s[j-1].l) {
            s[j].cnt1--;
            s[j-1].cnt2++;
          }
          j--;
        }
      }
    }

    out.println(area);

  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 32768);
    tokenizer = null;
  }

  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }

  public long nextLong() {
    return Long.parseLong(next());
  }

  public double nextDouble() {
    return Double.parseDouble(next());
  }
}
