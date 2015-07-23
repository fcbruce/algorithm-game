/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 22 Jul 2015 08:25:25 AM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;
  
  void solve() {
    
    while (true) {
      int n,m,a,b;
      try {
        n=nextInt();
      } catch (Exception ex) {
        return ;
      }
      m=nextInt();
      a=nextInt();
      b=nextInt();

      int[] x = new int [n+1];
      for (int i=1;i<=n;i++) x[i]=nextInt();

      BigInteger[][] dp = new BigInteger[n+1][m+1];

      for (int i=0;i<=m;i++) dp[0][i]=BigInteger.ZERO;
      dp[0][0]=BigInteger.ONE;

      for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
          dp[i][j] = BigInteger.ZERO;
          for (int k=a;k<=b;k++) {
            int gap=Math.abs(k-x[i]);
            if (gap<=j) dp[i][j]=dp[i][j].add(dp[i-1][j-gap]);
          }
        }
      }

      BigInteger sum = BigInteger.ZERO;
      for (int i=0;i<=m;i++) sum = sum.add(dp[n][i]);
      
      BigInteger total = new BigInteger(new Integer(b-a+1).toString());

      total = total.pow(n);

      BigInteger gcd = total.gcd(sum);

      sum = sum.divide(gcd);
      total = total.divide(gcd);

      out.println(sum + "/" + total);
    }
    
  }
  
  void run() throws Exception {
    in = System.in;
    out = new PrintWriter(System.out);
    solve();
    out.flush();
  }
  
  public static void main(String[] args) throws Exception { new Main().run(); }
  
  private byte[] inbuf = new byte[1024];
  private int lenbuf = 0, ptrbuf = 0;
  
  private int readByte() {
    if (lenbuf == -1) throw new InputMismatchException();
    if (ptrbuf >= lenbuf){
      ptrbuf = 0;
      try { lenbuf = in.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
      if (lenbuf <= 0) return -1;
    }
    return inbuf[ptrbuf++];
  }
  
  private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
  private int skip() { int b; while ((b = readByte()) != -1 && isSpaceChar(b)); return b; }
  
  private double nextDouble() { return Double.parseDouble(nextString()); }
  private char nextChar() { 
    int b = readByte();
    if (b==-1) throw new InputMismatchException();
    else return (char)b;
  }
  
  private String nextString() {
    int b = skip();
    if (b == -1) throw new InputMismatchException();
    StringBuilder sb = new StringBuilder();
    while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
      sb.appendCodePoint(b);
      b = readByte();
    }
    return sb.toString();
  }
  
  private char[] nextString(int n) {
    char[] buf = new char[n];
    int b = skip(), p = 0;
    while (p < n && !(isSpaceChar(b))) {
      buf[p++] = (char)b;
      b = readByte();
    }
    return n == p ? buf : Arrays.copyOf(buf, p);
  }
  
  private int[] nextArray(int n) {
    int[] a = new int[n];
    for (int i = 0;i < n;i++) a[i] = nextInt();
    return a;
  }
  
  private int nextInt() {
    int num = 0, b;
    boolean minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == -1) throw new InputMismatchException();
    if (b == '-') {
      minus = true;
      b = readByte();
    }
    
    while (true) {
      if (b >= '0' && b <= '9') {
        num = num * 10 + (b - '0');
      } else { 
        return minus ? -num : num;
      }
      b = readByte();
    }
  }
  
  private long nextLong() {
    long num = 0;
    int b;
    boolean minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == -1) throw new InputMismatchException();
    if (b == '-'){
      minus = true;
      b = readByte();
    }
    
    while (true) {
      if (b >= '0' && b <= '9') {
        num = num * 10 + (b - '0');
      } else {
        return minus ? -num : num;
      }
      b = readByte();
    }
  }
}
