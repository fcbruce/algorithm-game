/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 20 Feb 2015 12:46:25 PM CST
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
    try{
      while (true) {
        long n,p,q,k,a,b;
        n=in.nextInt();
        p=in.nextInt();
        q=in.nextInt();
        k=19960505l*19941129l;
        a=0;
        b=0;
        for (int i=0;i<32;i++) {
          for (int j=0;j<32;j++) {
            long res=((p*(n-1)+(p*(n-1)<<i))>>j)+q;
            if (res>=n*q && res<k) {
              k=res;
              a=i;
              b=j;
            }
          }
        }

        out.printf("%d %d %d\n",k,a,b);
      }
    } catch (Exception e){}


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
