class Solution {
public:
    int maximum(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+maximum(i+2,nums,dp);
        int ntake=0+maximum(i+1,nums,dp);
        return dp[i]=max(take,ntake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return maximum(0,nums,dp);
    }
};