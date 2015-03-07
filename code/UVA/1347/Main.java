/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 07 Mar 2015 06:10:36 PM CST
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

  double[][] dp;

  double[] x,y;
  int n;
  
  double dis(int i,int j) {
    double a=x[i]-x[j];
    double b=y[i]-y[j];
    return Math.sqrt(a*a+b*b);
  }

  double dfs(int i,int j) {

    if (dp[i][j]<1e10) return dp[i][j];

    if (i==n-2) {
      dp[i][j]=dis(n-2,n-1)+dis(j,n-1);
      return dp[i][j];
    }

    dp[i][j]=Math.min(dis(i,i+1)+dfs(i+1,j),dis(j,i+1)+dfs(i+1,i));
    return dp[i][j];
  }

  public void run(InputReader in,PrintWriter out) {

    dp = new double [1007][1007];
    x = new double [1007];
    y = new double [1007];

    while (true) {
      try {
        n=in.nextInt();
      } catch (Exception ex) {
        return ;
      }

      for (int i=0;i<n;i++) {
        x[i]=in.nextDouble();
        y[i]=in.nextDouble();
      }

      for (int i=0;i<n;i++) for (int j=0;j<n;j++) dp[i][j]=1e10+7.0;

      out.printf("%.2f\n",dfs(1,0)+dis(0,1));
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
