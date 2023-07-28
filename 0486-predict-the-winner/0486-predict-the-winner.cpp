class Solution {
public:
    int findIt(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        // if(dp[i][j]!=-1)return dp[i][j];
        int sum1=nums[i]+min(findIt(i+2,j,nums,dp),findIt(i+1,j-1,nums,dp));
        int sum2=nums[j]+min(findIt(i+1,j-1,nums,dp),findIt(i,j-2,nums,dp));
        
        return max(sum1,sum2);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int maxi=findIt(0,n-1,nums,dp);
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return maxi>=sum-maxi;
    }
};
