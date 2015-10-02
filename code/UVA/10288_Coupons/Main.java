/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 02 Oct 2015 01:06:15 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;

  class Fraction {
    long numerator;
    long denominator;

    Fraction() {
      numerator = 0;
      denominator = 1;
    }

    Fraction(long n, long d) {
      numerator = n;
      denominator = d;
    }

    long gcd(long a, long b) {
      if (b == 0) return a;
      return gcd(b, a % b);
    }

    Fraction add(Fraction rhs) {
      long n = numerator * rhs.denominator + rhs.numerator * denominator;
      long d = denominator * rhs.denominator;
      long g = gcd(n, d);
      return new Fraction(n / g, d / g);
    }

    void print() {
      long integerPart = numerator / denominator;
      if (numerator % denominator == 0) {
        out.println(integerPart);
      } else {
        long k = integerPart;
        int space = 0;
        while (k > 0) {
          space++;
          k /= 10;
        }
        if (space > 0) space += 1;
        for (int i = 0; i < space; i++) out.print(" ");
        out.printf("%d", numerator % denominator);
        out.println();
        if (integerPart > 0) {
          out.print(integerPart + " ");
          int dash = 0;
          k = denominator;
          while (k > 0) {
            dash++;
            k /= 10;
          }
          while (dash-- > 0) out.print("-");
          out.println();
        }
        for (int i = 0; i < space; i++) out.print(" ");
        out.printf("%d", denominator);
        out.println();
      }
    }
  }
  
  void solve() {
    
    while (true) {
      long n;
      try {
        n = nextLong();
      } catch (Exception ex) {
        break;
      }

      Fraction res = new Fraction();
      for (int i = 0; i < n; i++) res = res.add(new Fraction(n, n - i));

      res.print();
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
