/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 31 Mar 2015 10:51:27 AM CST
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

  boolean check(long dis,int []stalls,int n,int c) {
    
    int res=1;
    for (int i=1,j=0;i<n;i++) {
      if (stalls[i]-stalls[j]>=dis) {
        res++;
        j=i;
      }

      if (res==c) return true;
    }

    return false;
  }

  public void run(InputReader in,PrintWriter out) {

    int n=in.nextInt();
    int c=in.nextInt();

    int []stalls=new int [n];

    long l=1l<<32,r=0;

    for (int i=0;i<n;i++)  stalls[i]=in.nextInt();

    Arrays.sort(stalls);

    for (int i=1;i<n;i++) l=Math.min(l,stalls[i]-stalls[i-1]);

    r=stalls[n-1]-stalls[0];

    long res=0;

    while (l<=r) {
      long mid=l+r>>1;

      if (check(mid,stalls,n,c)) {
        res=mid;
        l=mid+1;
      }
      else r=mid-1;
    }

    out.println(res);
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
