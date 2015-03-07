/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Mar 2015 10:21:59 AM CST
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
  public void run(InputReader in,PrintWriter out) {
    int[] a=new int [100007];

    int T_T=in.nextInt();

    while (T_T-->0) {
      int n=in.nextInt();
      int k=in.nextInt();

      for (int i=0;i<n;i++) a[i]=in.nextInt();

      Arrays.sort(a,0,n);

      long cnt=0;
      int f=0,r=1;

      while (r<n) {
        while (f<=r && a[f]+k<a[r]) f++;
        cnt+=r-f;
        r++;
      }

      out.println(cnt);
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
