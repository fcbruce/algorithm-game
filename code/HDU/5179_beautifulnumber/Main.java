/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Mar 2015 10:43:43 AM CST
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

  long []a;
  int cnt;

  void dfs(long x) {
    a[cnt++]=x;

    long k=x;
    int n=0;
    while (k!=0) {
      n++;
      k/=10;
    }

    if (n==9) return ;

    for (long i=9;i>0;i--) {
      k=x;
      boolean ok=true;
      while (k!=0) {
        long m=k%10;
        if (m%i!=0) {
          ok=false;
          break;
        }
        k/=10;
      }
      if (ok) dfs(x*10+i);
    }
  }
  
  public void run(InputReader in,PrintWriter out) {

    a=new long [2333];
    cnt=0;
    
    for (int i=9;i>0;i--) dfs((long)i);

    Arrays.sort(a,0,cnt);

    int T_T=in.nextInt();

    while (T_T-->0) {
      int l=in.nextInt();
      int r=in.nextInt();

      int res=0;
      for (int i=0;i<cnt;i++)
        if (l<=a[i] && a[i]<=r) res++;

      out.println(res);
    }

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
