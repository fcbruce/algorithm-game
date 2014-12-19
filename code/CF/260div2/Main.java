import java.util.*;
import java.math.*;
//import java.io.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
	
	    String s;
	    //s=in.next();
        BigInteger a,b,c;
        b=BigInteger.valueOf(4);
        a=in.nextBigInteger();
        //a=BigInteger.valueOf(s);
        //a.BigInteger(s);
        c=a.remainder(b);
        if (c.equals(BigInteger.ZERO))
	    {
		    System.out.println(4);
	    }
        else
        {
            System.out.println(0);
        }
        
       

        
    }
}
