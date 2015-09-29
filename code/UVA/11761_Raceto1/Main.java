/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 29 Sep 2015 06:36:03 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;
  final int maxn = 1000001;

  int generatePrime(int []prime) {
    int pc = 0;
    boolean []isprime = new boolean [maxn];
    Arrays.fill(isprime, true);

    isprime[0] = isprime[1] = false;

    for (int i = 2; i < maxn; i++) {
      if (!isprime[i]) continue ;
      prime[pc++] = i;
      for (int j = i << 1; j < maxn; j += i) 
        isprime[j] = false;
    }

    return pc;
  }

  double dfs(double []dp, int []prime, int pc, int n) {
    if (dp[n] > -0.5) return dp[n];

    dp[n] = 0;

    int p = 0, g = 0;
    for (int i = 0; i < pc && prime[i] <= n; i++) {
      p++;
      if (n % prime[i] == 0) {
        dp[n] += dfs(dp, prime, pc, n / prime[i]);
        g++;
      }
    }

    dp[n] += p;
    dp[n] /= g;

    return dp[n];
  }
  
  void solve() {

    double []dp = new double [maxn];
    Arrays.fill(dp, -1.0);
    dp[1] = 0;

    int []prime = new int [maxn];
    int pc = generatePrime(prime);

    int T_T = nextInt(), __ = 0;

    while (T_T-->0) {

      int n = nextInt();

      out.printf("Case %d: %.8f\n", ++__, dfs(dp, prime, pc, n));
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
