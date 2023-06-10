class Solution {
public:
    int nways(int ind,vector<int>& nums,int target,vector<vector<int>>&dp){
     
        if(ind>nums.size())return 0;
        if(ind==nums.size())return target==0;
        if(dp[ind][target]!=-1)return dp[ind][target];
       int take=0,ntake=0;
        if(target>=nums[ind]){
            take=nways(0,nums,target-nums[ind],dp);
        }
        ntake=nways(ind+1,nums,target,dp);
        return dp[ind][target]=take+ntake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return nways(0,nums,target,dp);
    }
};