class Solution {
public:
    const int MOD = 1e9 + 7;  // Modulus for calculations
    vector<long long> dp;    // Array for memoization

    int countOrders(int numberOfPairs) {
        dp.resize(numberOfPairs + 1); // Initialize memoization array

        // Base case: there is one way to arrange 0 pairs
        dp[0] = 1;

        // Iterate over all values of pairs from 1 to n
        for (int currentPairs = 1; currentPairs <= numberOfPairs; currentPairs++) {
            // Calculate the number of valid orders for the current number of pairs
            dp[currentPairs] = dp[currentPairs - 1] * (2 * currentPairs - 1) * currentPairs % MOD;
        }

        return dp[numberOfPairs]; // Return the result for n pairs
    }
};