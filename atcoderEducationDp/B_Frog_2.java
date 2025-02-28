// run on java 1.8.0_162

import java.io.*;
import java.util.*;

public class B_Frog_2 {

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

        int k = cin.nextInt();

        int arr[] = new int[n];

        for(int i = 0 ; i < n ; i++){
            arr[i] = cin.nextInt();
        }

        int dp[] = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for(int i = 1 ; i< n ; i++){
            for(int j = 1; j<=k && i-j >=0; j++){
                dp[i] =Math.min(dp[i] , Math.abs(arr[i-j]-arr[i]) + dp[i-j]);
            }
        }
        // for(int i : dp)cout.println(i);
        cout.println(dp[n-1]);
        cout.flush();

}
}
