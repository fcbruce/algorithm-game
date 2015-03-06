/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 06 Mar 2015 07:43:36 PM CST
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

  static int inf = 0x3f3f3f3f;
  static int maxn = 107;
  static int maxm = 100007;

  class squ {
    public int a,b,h;

    public void set(int x,int y,int z) {
      a=Math.min(x,y);
      b=Math.max(x,y);
      h=z;
    }
  }

  squ []sq; 

  int []fir;
  int[] u,v,w,nex;
  int e_max;

  boolean []inq;
  int []d;
  int []q;

  void add_edge(int s,int t,int c) {
    int e=e_max++;
    u[e]=s;v[e]=t;w[e]=c;
    nex[e]=fir[u[e]];fir[u[e]]=e;
  }

  void spfa(int s) {
    int f,r;
    Arrays.fill(d,0);
    Arrays.fill(inq,false);

    q[f=r=0]=s;
    while (f<=r) {
      int x=q[f++];
      inq[x]=false;

      for (int e=fir[x];e!=-1;e=nex[e]) {
        if (d[v[e]]<d[x]+w[e]) {
          d[v[e]]=d[x]+w[e];
          if (!inq[v[e]]) {
            inq[v[e]]=true;
            q[++r]=v[e];
          }
        }
      }
    }
  }

  public void run(InputReader in,PrintWriter out) {

    fir = new int [maxn];
    u = new int [maxm];
    v = new int [maxm];
    w = new int [maxm];
    nex = new int [maxm];
    e_max=0;

    d = new int [maxn];
    inq = new boolean [maxn];
    q = new int [maxm<<3];

    sq = new squ [maxn];
    for (int i=0;i<maxn;i++) sq[i]= new squ();

    int n;

    int __=0;

    while ((n=in.nextInt())!=0) {
      int m=0;
      sq[m++].set(inf,inf,0);

      Arrays.fill(fir,-1);
      e_max=0;

      for (int i=0;i<n;i++) {
        int a=in.nextInt();
        int b=in.nextInt();
        int c=in.nextInt();
        sq[m++].set(a,b,c);
        sq[m++].set(a,c,b);
        sq[m++].set(c,b,a);
      }

      for (int i=0;i<m;i++) {
        for (int j=0;j<m;j++) {
          if (sq[i].a<sq[j].a && sq[i].b<sq[j].b) add_edge(j,i,sq[i].h);
        }
      }

      spfa(0);

      int max=0;
      
      for (int i=0;i<m;i++) max=Math.max(max,d[i]);

      out.printf("Case %d: maximum height = %d\n",++__,max);
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
