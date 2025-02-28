// run on java 1.8.0_162

import java.io.*;
import java.util.*;

public class C_Vacation {

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
        int n = cin.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];

        for(int i = 0 ; i < n ; i++){
            a[i] = cin.nextInt();
            b[i] = cin.nextInt();
            c[i] = cin.nextInt();
        }
        int[][] dp = new int[n][3];
        dp[0][0] = a[0];
        dp[0][1] = b[0];
        dp[0][2] = c[0];

        for(int i = 1; i < n ; i++){
            dp[i][0] = a[i] + Math.max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b[i] + Math.max(dp[i-1][0] , dp[i-1][2]);
            dp[i][2] = c[i] + Math.max(dp[i-1][0] , dp[i-1][1]);
        }
        int res = Math.max(dp[n-1][0],dp[n-1][1]);
        res = Math.max(res , dp[n-1][2]);
        cout.println(res);
        cout.flush();

}
}
