// run on java 1.8.0_162

import java.io.*;
import java.util.*;


public class F_LCS {

    static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new IllegalStateException(e);
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    
    public static void main(String args[]) {
        FastScanner cin = new FastScanner();
        PrintWriter cout = new PrintWriter(System.out);
        String s = cin.next();
        String t = cin.next();

        int dp[][] = new int[s.length()+1][t.length()+1];


        for(int i = 1 ; i <= s.length() ; i++){
            for(int j = 1 ; j <= t.length() ; j++){
                if(s.charAt(i-1) == t.charAt(j-1)){
                    dp[i][j] =  1  + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
        int ans = 0;
        for(int[] row : dp){
            for(int col : row){
                ans = Math.max(ans , col);
            }
        }
        char res[] = new char[ans];
        int r = s.length();
        int c = t.length();
        int index = ans-1;
        while(r>0 && c>0){
            if(s.charAt(r-1) == t.charAt(c-1)){
                res[index]=s.charAt(r-1);
                index--;
                r--;
                c--;
            }
            else if(dp[r-1][c]>dp[r][c-1])r--;
            else c--;
        }
        cout.println(new String(res));
        cout.flush();
    }

}

