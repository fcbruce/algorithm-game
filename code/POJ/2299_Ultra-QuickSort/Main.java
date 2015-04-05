/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 03 Apr 2015 07:17:20 PM CST
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

  int []a;

  long merge(int l,int r) {
    if (l+1==r) return 0;

    int mid=l+r>>1;

    long res=merge(l,mid)+merge(mid,r);

    int []b=new int [r-l];
    int k=0,i=l,j=mid;

    while (i<mid && j<r) {
      if (a[i]<=a[j]) b[k++]=a[i++] ;
      else {
        res+=mid-i;
        b[k++]=a[j++];
      }
    }
    while (i<mid) b[k++]=a[i++];
    while (j<r) b[k++]=a[j++];

    for (i=l;i<r;i++) a[i]=b[i-l];
    return res;

  }

  public void run(InputReader in,PrintWriter out) {

    int n;
    a=new int [500007];
    
    while ((n=in.nextInt())!=0) {
      for (int i=0;i<n;i++) a[i]=in.nextInt();

      long res=merge(0,n);

      out.println(res);

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
