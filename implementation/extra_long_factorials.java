/*
https://www.hackerrank.com/challenges/extra-long-factorials
*/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer N;
        N = in.nextInt();
        
        BigInteger sum = new BigInteger(N.toString());

        for (Integer i=1; i<N; i++) {
            sum = sum.multiply(BigInteger.valueOf(N-i));
        }
        System.out.println(sum);
    }
}
