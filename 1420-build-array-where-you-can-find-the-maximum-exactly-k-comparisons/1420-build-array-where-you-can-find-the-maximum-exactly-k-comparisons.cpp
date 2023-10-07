class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const int MOD = 1000000007;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k, vector<long long>(m, 0)));
        
        for (int i = 0; i < m; ++i) {
            dp[0][0][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int cost = 0; cost < min(i + 1, k); ++cost) {
                for (int maxVal = 0; maxVal < m; ++maxVal) {
                    long long sum = 0;
                    sum += dp[i - 1][cost][maxVal] * (maxVal + 1);
                    sum %= MOD;
                    
                    if (cost != 0) {
                        for (int prevMax = 0; prevMax < maxVal; ++prevMax) {
                            sum += dp[i - 1][cost - 1][prevMax];
                            sum %= MOD;
                        }
                    }
                    dp[i][cost][maxVal] = sum;
                }
            }
        }
        
        long long ans = 0;
        for (int maxVal = 0; maxVal < m; ++maxVal) {
            ans += dp[n - 1][k - 1][maxVal];
            ans %= MOD;
        }
        
        return static_cast<int>(ans);
    }
};