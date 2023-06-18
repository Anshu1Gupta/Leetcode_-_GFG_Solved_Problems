class Solution {
public:
    int m, n;
    vector<pair<int,int>> dir = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    int dp[1001][1001];
    

    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int answer = 1;
        
        for(auto &dir : dir) {
            int i_ = i + dir.first;
            int j_ = j + dir.second;
            
            if(i_<n&&j_<m&&i_>=0&&j_>=0&& grid[i_][j_] < grid[i][j]) {
                answer = (answer + dfs(grid, i_, j_)) % MOD;
            }
        }
        
        return dp[i][j] = answer;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                result = (result + dfs(grid, i, j)) % MOD;
                
            }
        }
        
        
        return result;
    }
};