/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 29 Mar 2015 01:47:56 PM CST
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

    char []s=in.next().toCharArray();
    int n=in.nextInt();
    boolean []p=new boolean [s.length];
    for (int i=0;i<n;i++) {
      int a=in.nextInt()-1;
      p[a]=!p[a];
    }

    boolean f=false;
    for (int i=0;i<s.length/2;i++) {
      if (p[i]) f=!f;
      if (f) {
        char t=s[i];
        s[i]=s[s.length-1-i];
        s[s.length-1-i]=t;
      }
    }

    out.println(s);



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
