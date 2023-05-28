class Solution {
public:
int maximum(int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n-1&&j==m-1){
        return 1;
    }
    if(i<0||i>=n||j<0||j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cost1=maximum(i+1,j,n,m,dp);
    int cost2=maximum(i,j+1,n,m,dp);
    dp[i][j]=(cost1+cost2);
    return dp[i][j];
}
    int uniquePaths(int n, int m) {

vector<vector<int>>dp(n,vector<int>(m,-1));
        return maximum(0,0,n,m,dp);
    }
};