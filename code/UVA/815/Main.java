/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 20 Feb 2015 01:31:16 PM CST
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

  static int dcmp(double l,double r) {
    if (Math.abs(r-l) < 1e-8) return 0;
    if (l>r) return 1;
    else return -1;
  }

  public void run(InputReader in,PrintWriter out) {
    
    int __=0;

    while (true){
      int n=in.nextInt();
      int m=in.nextInt();
      if (n==0 && m==0) break;
      n*=m;

      int[] h = new int [n+1];
      for (int i=0;i<n;i++) h[i]=in.nextInt();
      h[n]=19960505;

      Arrays.sort(h);
      double res=in.nextDouble()/100.0;
      double pers=0;
      for (int i=1;i<n+1;i++) {
        res+=h[i-1];
        if (dcmp(res/i,h[i])<=0){
          res/=i;
          pers=i*100.0/n;
          break;
        }
      }
     
      out.printf("Region %d\n",++__);
      out.printf("Water level is %.2f meters.\n",res);
      out.printf("%.2f percent of the region is under water.\n\n",pers);

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
