class Solution {
public:
    bool isPossible(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0){
            if(nums[i]==target)return true;
            return false;   
        }
        if(dp[i][target]!=-1)return dp[i][target];
    bool take=false,ntake=false;
       if(target>=nums[i]){
           take=isPossible(i-1,nums,target-nums[i],dp);
       }
         ntake=isPossible(i-1,nums,target,dp);
        return dp[i][target]=take|ntake;
       
        
    }
    bool canPartition(vector<int>& nums) {
    int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        
        if(sum%2==1)return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // int target=sum/2;
        return isPossible(n-1,nums,target,dp);
    }
};