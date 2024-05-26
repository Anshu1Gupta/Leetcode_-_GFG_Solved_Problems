class Solution {
public:
    const long long m = 1e9 + 7;
    int checkRecord(int n) {
        int dp[3][2];
     
        dp[0][0] = dp[0][1] = dp[1][0] = 1;
        for (int i = 1; i < n; i++) {
            int newdp[3][2];
            newdp[0][0] = (dp[0][0] % m + dp[1][0] % m + dp[2][0] % m) % m;
            newdp[1][0] = dp[0][0] % m;
            newdp[2][0] = dp[1][0] % m;
            newdp[0][1] = (dp[0][0] % m + dp[1][0] % m + dp[2][0] % m + 
                           dp[0][1] % m + dp[1][1] % m + dp[2][1] % m) % m;
            newdp[1][1] = dp[0][1] % m;
            newdp[2][1] = dp[1][1] % m;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    dp[i][j] = newdp[i][j];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                ans = (ans % m + dp[i][j] % m) % m;
            }
        }
        return ans % m;
    }
};