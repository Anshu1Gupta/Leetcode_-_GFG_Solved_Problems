class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix.size();
        // int mini=1e8;
        vector<vector<int>>dp(n,vector<int>(m));
        for(int j=0;j<m;j++){
          dp[0][j]=matrix[0][j];
       }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                int first=dp[i-1][j];
                int second=j-1>=0?dp[i-1][j-1]:INT_MAX;
                int third= j+1<m?dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min({first,second,third});
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,dp[n-1][j]);
        }
       return ans;
    }
};