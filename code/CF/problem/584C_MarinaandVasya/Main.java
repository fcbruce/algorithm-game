/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Oct 2015 09:43:43 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;
  
  void solve() {

    int n = nextInt();
    int diff = nextInt();

    char []s1 = nextString(n);
    char []s2 = nextString(n);

    char []s3 = new char [n];

    int same = n - diff;

    for (int i = 0; i < n && same > 0; i++) {
      if (s1[i] == s2[i]) {
        s3[i] = s1[i];
        same--;
      }
    }

    int diff1 = 0, diff2 = 0;
    int same1 = same, same2 = same;

    for (int i = 0; i < n; i++) {
      if (s3[i] == '\0') {
        if (same1 == 0 && same2 == 0) {
          for (char c = 'a'; c <= 'z'; c++) {
            if (c != s1[i] && c != s2[i]) {
              s3[i] = c;
              break;
            }
          }
        } else if (same1 < same2) {
          s3[i] = s2[i];
          same2--;
        } else {
          s3[i] = s1[i];
          same1--;
        }
      }
    }

    if (same1 != 0 || same2 != 0) out.println("-1");
    else out.println(s3);


    
    
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
