/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
			Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		while(t!=0)
		{
		//	str=in.next();
			String str;
			str=in.next();
			BigInteger a=new BigInteger("1");
			BigInteger b=new BigInteger(str);
			BigInteger zero=new BigInteger("0");
			BigInteger one=new BigInteger("1");
			while(zero.compareTo(b)!=0)
			{
				a=a.multiply(b);
				b=b.subtract(one);
			}
			System.out.println(a);
			t-=1;
		}
	
	}
}
