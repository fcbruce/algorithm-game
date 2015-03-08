/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 12:01:15 PM CST
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
  long[] f;
  HashMap<Long,Boolean> s;
  
  boolean dfs(long x) {
    if (s.containsKey(x)) return s.get(x);

    int id=Arrays.binarySearch(f,x);
    if (id>=0) {
      s.put(x,true);
      return true;
    }

    for (int i=3;f[i]*f[i]<=x;i++) 
      if (x%f[i]==0 && dfs(x/f[i])) {
        s.put(x,true);
        return true;
      }

    s.put(x,false);
    return false;
  }

  public void run(InputReader in,PrintWriter out) {
    f = new long [50];
    s=new HashMap<Long,Boolean>();

    f[0]=0;f[1]=1;
    for (int i=2;i<50;i++) f[i]=f[i-2]+f[i-1];

    int T_T=in.nextInt();

    while (T_T-->0) {
      long n=in.nextLong();
      
      if (dfs(n)) out.println("Yes");
      else out.println("No");
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
