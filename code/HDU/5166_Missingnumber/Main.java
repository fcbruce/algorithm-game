/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Mar 2015 11:40:19 PM CST
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
    int[] a=new int [1007];
    int T_T=in.nextInt();
    
    while (T_T-->0) {
      int n=in.nextInt();
      for (int i=0;i<n;i++) a[i]=in.nextInt();
      Arrays.sort(a,0,n);

      boolean first=true;
      for (int i=1;i<=n+2;i++) {
        boolean exist=false;

        for (int j=0;j<n;j++) {
          if (a[j]==i) {
            exist=true;
            break;
          }
        }

        if (!exist) {
          out.printf("%d",i);
          if (first) {
            out.printf(" ");
            first=false;
          } else {
            out.println("");
            break;
          }
        }
      }
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
