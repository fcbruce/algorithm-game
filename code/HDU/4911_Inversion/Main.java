/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 31 Mar 2015 06:20:47 PM CST
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

  void update(int p,int k,int l,int r,int []cntv) {
    if (l+1==r) {
      cntv[k]++;
      return ;
    }
    
    int m=l+r>>1;
    if (p<m) update(p,k*2+1,l,m,cntv);
    else update(p,k*2+2,m,r,cntv);

    cntv[k]=cntv[k*2+1]+cntv[k*2+2];
  }

  int query(int a,int b,int k,int l,int r,int []cntv) {
    if (b<=l || r<=a) return 0;
    if (a<=l && r<=b) return cntv[k];

    return query(a,b,k*2+1,l,l+r>>1,cntv)+query(a,b,k*2+2,l+r>>1,r,cntv);
  }

  public void run(InputReader in,PrintWriter out) {
    int []a=new int [100007];
    int []b=new int [100007];
    int []cntv=new int [100007<<2];

    while (true) {
      int n;
      try {
        n=in.nextInt();
      } catch (Exception ex) {return ;}

      int k=in.nextInt();

      for (int i=0;i<n;i++) b[i]=a[i]=in.nextInt();

      Arrays.sort(b,0,n);

      Arrays.fill(cntv,0);

      long res=0l;

      for (int i=0;i<n;i++) {
        int p=Arrays.binarySearch(b,0,n,a[i]);
        res+=query(p+1,n,0,0,n,cntv);
        update(p,0,0,n,cntv);
      }

      out.println(Math.max(0l,res-k));
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
