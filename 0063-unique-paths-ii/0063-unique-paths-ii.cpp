class Solution {
public:
    
    int unique(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(x==0&&y==0){
            return grid[0][0]!=1;
        }
        if(x<0||y<0||grid[x][y]==1)return 0;
        
        
        if(dp[x][y]!=-1)return dp[x][y];
  
        int up=unique(x-1,y,grid,dp);
        int left=unique(x,y-1,grid,dp);
        
       
        return dp[x][y]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        if(obstacleGrid[n-1][m-1]==1)return 0;
        return unique(n-1,m-1,obstacleGrid,dp);
    }
};