/*
 * TightWords.java
 * 
 * Copyright 2024 Omar Muhammetkulyyev <omar99@omar99-UX330UAR>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy f the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

import java.util.Scanner;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.math.MathContext;

public class TightWords {
	
	public static void main (String[] args) {
		Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()){
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            solve(n, k);
        }
	}
    
    public static void solve(int n, int k){
        // System.out.printf("%d %d\n", n, k);
        BigInteger[][] dp = new BigInteger[n][k+1];
        // System.out.printf("*****\n");
        for(int j=0; j<n; j++){
            for(int i=0; i<=k; i++){
                dp[j][i] = new BigInteger(j == 0 ? "1" : "0");
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                dp[i][j] = dp[i][j].add(dp[i-1][j]);
                if(j > 0) dp[i][j] = dp[i][j].add(dp[i-1][j-1]);
                if(j < k) dp[i][j] = dp[i][j].add(dp[i-1][j+1]);
            }
        }
        BigInteger numer = new BigInteger("0");
        for(int i=0; i<=k; i++){
            numer = numer.add(dp[n-1][i]);
        }
        BigInteger denom = new BigInteger("1");
        for(int i=0; i<n; i++){
            denom = denom.multiply(new BigInteger(Integer.toString(k+1)));
        }
        // System.out.println("numerator: " + numer + ", denominator: " + denom);
        BigDecimal ratio = new BigDecimal(numer);
        ratio = ratio.divide(new BigDecimal(denom), MathContext.DECIMAL64);
        ratio = ratio.multiply(new BigDecimal("100"));
        System.out.println(ratio);
    }
}

