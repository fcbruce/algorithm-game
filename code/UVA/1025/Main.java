/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 04 Mar 2015 06:48:21 PM CST
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
  static int inf = 0x3f3f3f3f;
  public void run(InputReader in,PrintWriter out) {
    int n,T,m1,m2;
    int []t = new int [55];
    boolean [][]toleft = new boolean [433][55];
    boolean [][]toright = new boolean [433][55];
    int [][]dp = new int [233][55];
    int __=0;

    while ((n=in.nextInt())!=0) {
      T=in.nextInt();
      for (int i=1;i<n;i++) t[i]=in.nextInt();

      for (int i=0;i<=T;i++) Arrays.fill(toright[i],false);
      for (int i=0;i<=T;i++) Arrays.fill(toleft[i],false);

      m1=in.nextInt();
      for (int i=0;i<m1;i++) {
        int s=in.nextInt();
        for (int j=1;j<n;j++) {
          toright[s][j]=true;
          s+=t[j];
        }
        toright[s][n]=true;
      }

      m2=in.nextInt();
      for (int i=0;i<m2;i++) {
        int s=in.nextInt();
        for (int j=n;j>1;j--) {
          toleft[s][j]=true;
          s+=t[j-1];
        }
        toleft[s][1]=true;
      }
      
      Arrays.fill(dp[T],inf);

      dp[T][n]=0;

      for (int i=T-1;i>=0;i--) {
        for (int j=1;j<=n;j++) {
          dp[i][j]=dp[i+1][j]+1;
          if (j<n && toright[i][j] && i+t[j]<=T)
            dp[i][j]=Math.min(dp[i][j],dp[i+t[j]][j+1]);
          if (j>1 && toleft[i][j] && i+t[j-1]<=T)
            dp[i][j]=Math.min(dp[i][j],dp[i+t[j-1]][j-1]);
        }
      }
      
      out.printf("Case Number %d: ",++__);
      if (dp[0][1]>=inf) out.println("impossible");
      else out.println(dp[0][1]);
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
