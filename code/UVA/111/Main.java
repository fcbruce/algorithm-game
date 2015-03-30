/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 30 Mar 2015 09:28:13 PM CST
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

  int []h;
  int []a;

  public void run(InputReader in,PrintWriter out) {

    int n=in.nextInt();
    h=new int [n+1];
    a=new int [n+1];

    for (int i=0;i<n;i++) {
      h[i]=in.nextInt()-1;
    }

    while (true) {
      try {
        a[in.nextInt()-1]=0;
      } catch (Exception ex) {
        return ;
      }

      for (int i=1;i<n;i++) a[in.nextInt()-1]=i;

      int []dp = new int [n];
      int max=0;

      for (int i=0;i<n;i++) {
        dp[i]=1;
        for (int j=0;j<i;j++) {
          if (h[a[i]]>h[a[j]]) {
            dp[i]=Math.max(dp[i],dp[j]+1);
          }
        }
        max=Math.max(max,dp[i]);
      }

      out.println(max);
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
