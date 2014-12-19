/*
 *
 * Author : fcbruce
 *
 * Time : Tue 30 Sep 2014 09:21:08 PM CST
 *
 */
import java.util.*;
public class A
{
  public static void main(String[] args)
  {
    Scanner cin = new Scanner(System.in);
    int n=cin.nextInt();
    int X=0,Y=0,x,y;
    boolean can_swap=false;

    for (int i=0;i<n;i++){
      x=cin.nextInt();
      y=cin.nextInt();
      X+=x;
      Y+=y;
      if ((x+y&1)!=0) can_swap=true;
    }

    if ((X&1)==0 && (Y&1)==0)
      System.out.println(0);
    else if ((X+Y&1)==0 && can_swap)
      System.out.println(1);
    else 
      System.out.println(-1);

  }
}
