class Solution {
public:
  int minimum(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(x==0&&y==0)return grid[x][y];
      if(x<0||y<0)return 1e9;
      
      if(dp[x][y]!=-1)return dp[x][y];
      int up=grid[x][y]+minimum(x-1,y,grid,dp);
      int left=grid[x][y]+minimum(x,y-1,grid,dp);
      return dp[x][y]=min(up,left);
  }
  int minPathSum(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   	 return minimum(n-1,m-1,grid,dp);
  }
};
