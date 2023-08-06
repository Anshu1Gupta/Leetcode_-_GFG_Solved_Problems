class Solution {
public:
    int MOD=1e9+7;
   int numMusicPlaylists(int n, int goal, int k)
    {
        vector<vector < long>> dp(goal + 1, vector<long> (n + 1, 0LL));
        dp[0][0] = 1;
       	//To do nothing case
        for (int len = 1; len <= goal; len++)
        {
           	//Traversing the length of playlist
            for (int uniq = 1; uniq <= min(len, n); uniq++)
           	//Traversing no of unique songs
            {
                long addNewSong = (dp[len - 1][uniq - 1] *(n - (uniq - 1))) % MOD;
                long replayOldSong = 0LL;
                if (uniq > k)
                    replayOldSong = (dp[len - 1][uniq] *(uniq - k)) % MOD;
                dp[len][uniq] = (addNewSong + replayOldSong) % MOD;
            }
        }
        return dp[goal][n];
    }


};