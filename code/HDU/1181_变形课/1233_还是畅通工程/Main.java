/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 01:15:32 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;

  int prim(int [][]G,int n) {
    boolean []vis = new boolean [n+1];
    int []d = new int [n+1];

    Arrays.fill(vis,0,n+1,false);
    Arrays.fill(d,0,n+1,0x3f3f3f3f);
    d[1]=0;

    int res=0;

    for (;;) {
      int v=-1;
      for (int i=1;i<=n;i++) if (!vis[i] && (v==-1 || d[v]>d[i])) v=i;

      if (v==-1) break;

      vis[v]=true;
      res+=d[v];
      
      for (int i=1;i<=n;i++) d[i]=Math.min(d[i],G[v][i]);
    }

    return res;
  }
  
  void solve() {
    int [][]G= new int [107][107];
  
    int n;
    while (true) {
      n=nextInt();
      if (n==0) break;

      for (int i=0;i<n*(n-1)/2;i++) {
        int u=nextInt();
        int v=nextInt();
        int w=nextInt();
        G[u][v]=G[v][u]=w;
      }

      out.println(prim(G,n));
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
    if(lenbuf == -1)throw new InputMismatchException();
    if(ptrbuf >= lenbuf){
      ptrbuf = 0;
      try { lenbuf = in.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
      if (lenbuf <= 0)return -1;
    }
    return inbuf[ptrbuf++];
  }
  
  private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
  private int skip() { int b; while ((b = readByte()) != -1 && isSpaceChar(b)); return b; }
  
  private double nextDouble() { return Double.parseDouble(nextString()); }
  private char nextChar() { return (char)skip(); }
  
  private String nextString() {
    int b = skip();
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
