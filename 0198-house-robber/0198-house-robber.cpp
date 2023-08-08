class Solution {
public:
    int maxProfit(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size())return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        int take=nums[ind]+maxProfit(ind+2,nums,dp);
        int ntake=0+maxProfit(ind+1,nums,dp);
        
        return dp[ind]=max(take,ntake);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return maxProfit(0,nums,dp);
    }
};