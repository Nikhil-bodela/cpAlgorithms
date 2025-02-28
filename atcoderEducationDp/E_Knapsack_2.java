// run on java 1.8.0_162

import java.io.*;
import java.util.*;

public class E_Knapsack_2 {

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
        int V = 0;
        for(int i = 0 ; i < n ; i++) {
            weights[i] = cin.nextInt();
            values[i] = cin.nextInt();
            V+=values[i];
        }
        Long[] dp = new Long[V+1];
        Arrays.fill(dp , Long.MAX_VALUE);

        //dp[i] = min weight to get value exactly i
        dp[0] = 0L;
        for(int i = 0 ; i < n ; i++){
            for(int v = V-values[i] ; v >= 0 ; v--){
                if (dp[v] != Long.MAX_VALUE) {
                    dp[v + values[i]] = Math.min(dp[v + values[i]], dp[v] + weights[i]);
                }
            }
            
        }


        int res = 0;
        for(int i = 0 ; i <= V ; i++){
            if(dp[i] <= W){
                res = Math.max(res , i);
            }
        }
        cout.println(res);
        
        cout.flush();

}
}