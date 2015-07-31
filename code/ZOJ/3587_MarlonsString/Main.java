/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 31 Jul 2015 09:06:46 AM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;

  int [] get_fail(char []T) {
    int []nex = new int [T.length];
    nex[0]=-1;
    for (int i=1,j=-1;i<T.length;i++) {
      while (j>-1 && T[j+1]!=T[i]) j=nex[j];
      if (T[j+1]==T[i]) j++;
      nex[i]=j;
    }
    return nex;
  }
  
  long [] KMP(char []S, char []T) {
    int []nex = get_fail(T);
    long []cnt = new long [T.length];
    Arrays.fill(cnt,0);

    for (int i=0,j=-1;i<S.length;i++) {
      while (j>-1 && T[j+1]!=S[i]) j=nex[j];
      if (T[j+1]==S[i]) j++;
      if (j>-1) cnt[j]++;
      if (j+1==T.length) {
        j=nex[j];
      }
    }

    for (int i=T.length-1;i>=0;i--) {
      if (nex[i]>-1) cnt[nex[i]]+=cnt[i];
    }

    return cnt;
  }

  void solve() {
    
    int T_T=nextInt();

    while (T_T-->0) {

      String S=nextString();
      String T=nextString();

      long []cnt1=KMP(S.toCharArray(),T.toCharArray());

      S=new StringBuffer(S).reverse().toString();
      T=new StringBuffer(T).reverse().toString();

      long []cnt2=KMP(S.toCharArray(),T.toCharArray());

      long res=0;
      int l=cnt1.length;
      for (int i=0;i<l-1;i++) {
        res+=cnt1[i]*cnt2[l-i-2];
      }

      out.println(res);
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
