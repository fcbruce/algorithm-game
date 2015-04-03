/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 03 Apr 2015 07:54:48 PM CST
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

  class Star implements Comparable<Star> {
    int x,y;

    Star(int a,int b) {
      x=a;
      y=b;
    }

    public int compareTo(Star o) {
      return y-o.y;
    }
  }

  int []sum;
  int n;

  int lowbit(int x) {
    return x&-x;
  }

  int query(int x) {
    x++;
    int res=0;
    while (x>0) {
      res+=sum[x];
      x-=lowbit(x);
    }
    return res;
  }

  void add(int x) {
    x++;
    while (x<=n) {
      sum[x]++;
      x+=lowbit(x);
    }
  }

  public void run(InputReader in,PrintWriter out) {

    n=in.nextInt();

    sum=new int [n<<2];

    Star []s=new Star[n];

    int []X=new int [n];
    int []lv=new int [n];

    for (int i=0;i<n;i++) {
      int x=in.nextInt();
      int y=in.nextInt();
      s[i]=new Star(x,y);
      X[i]=x;
    }

    Arrays.sort(s);
    Arrays.sort(X);

    for (int i=0;i<n;i++) {
      int x=Arrays.binarySearch(X,s[i].x);
      lv[query(x)]++;
      add(x);
    }

    for (int i=0;i<n;i++) out.println(lv[i]);
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
