class Solution {
public:
    int unique(int x,int y,int n,int m,vector<vector<int>>&dp){
        if(x==0&&y==0)return 1;
        if(x<0||y<0)return 0;
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        int up=unique(x-1,y,n,m,dp);
        int left=unique(x,y-1,n,m,dp);
        
        return dp[x][y]=up+left;
        
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return unique(n-1,m-1,n,m,dp);
    }
};