// run on java 1.8.0_162

import java.io.*;
import java.util.*;

public class D_Knapsack_1 {

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
        int W= cin.nextInt();

        int[] weights = new int[n];
        int[] values = new int[n];

        for(int i = 0 ; i < n ; i++) {
            weights[i] = cin.nextInt();
            values[i] = cin.nextInt();
        }

        Long[] dp = new Long[W+1];
        Long res = 0L;
        Arrays.fill(dp, 0L);
        for(int i = 0 ; i < n ; i++){
                for(int w=W ; w-weights[i] >=0 ; w--){
                    dp[w] = Math.max(dp[w] , dp[w-weights[i]]+values[i]);
                }
            }
        
        cout.println(dp[W]);
        cout.flush();

}
}