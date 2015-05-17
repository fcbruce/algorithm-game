/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 02:47:46 PM CST
 *
 */
import java.util.*;
import java.math.*;
import java.io.*;
public class Main {
  InputStream in;
  PrintWriter out;

  int n,m;
  int [][]G;

  int []dx={0,0,1,-1};
  int []dy={1,-1,0,0};

  class node {
    int x,y,px,py,d;

    node (int x,int y,int px,int py,int d) {
      this.x=x;
      this.y=y;
      this.px=px;
      this.py=py;
      this.d=d;
    }
  }

  boolean ok(int x,int y) {
    return 0<=x && x<n && 0<=y && y<m && G[x][y]==0;
  }

  boolean dfs(int sx,int sy,int tx,int ty,boolean [][]go) {
    if (sx==tx && sy==ty) return true;
    go[sx][sy]=true;
    for (int i=0;i<4;i++) {
      int x=sx+dx[i];
      int y=sy+dy[i];
      if (ok(x,y) && !go[x][y] && dfs(x,y,tx,ty,go)) return true;
    }
    return false;
  }

  int bfs(int sx,int sy,int tx,int ty,int px,int py) {
    int f,r;
    node []q = new node [10000];
    boolean [][][]vis = new boolean [n][m][4];
    Arrays.fill(vis[sx][sy],0,4,true);
    q[f=r=0]= new node(sx,sy,px,py,0);

    while (f<=r) {
      node c = q[f++];
      if (c.x==tx && c.y==ty) return c.d;

      for (int i=0;i<4;i++) {
        int ppx=c.x-dx[i];
        int ppy=c.y-dy[i];
        int x=c.x+dx[i];
        int y=c.y+dy[i];

        G[c.x][c.y]=1;

        if (ok(x,y) && !vis[x][y][i] && ok(ppx,ppy)) {
          boolean [][]go = new boolean [n][m];
          if (dfs(c.px,c.py,ppx,ppy,go)) {
            q[++r] = new node(x,y,ppx,ppy,c.d+1);
            vis[x][y][i]=true;
          }
        }

        G[c.x][c.y]=0;
      }
    }

    return -1;
  }
  
  void solve() {
  
    int T_T=nextInt();

    while (T_T-->0) {
      n=nextInt();
      m=nextInt();
      G = new int [n][m];

      int sx=0,sy=0,tx=0,ty=0,px=0,py=0;

      for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        G[i][j]=nextInt();
        switch (G[i][j]) {
          case 2:
            sx=i;sy=j;G[i][j]=0;
            break;
          case 3:
            tx=i;ty=j;G[i][j]=0;
            break;
          case 4:
            px=i;py=j;G[i][j]=0;
            break;
        }
      }

      out.println(bfs(sx,sy,tx,ty,px,py));
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
