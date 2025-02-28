// run on java 1.8.0_162

import java.io.*;
import java.util.*;

public class A_Frog_1 {

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
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = cin.nextInt();
            // cout.println(x[i]);
        }
        
        // solve here

        int prev1 = Math.abs(x[1]-x[0]);
        int prev2 = 0;
        int res = prev1;
        for(int i = 2 ; i < n ; i++) {
            res = Math.min(Math.abs(x[i]-x[i-1])+prev1 , Math.abs(x[i] - x[i-2]) + prev2);
            prev2 = prev1;
            prev1 = res;
        }

        cout.println(res);
        

        cout.flush();
    }

    

}