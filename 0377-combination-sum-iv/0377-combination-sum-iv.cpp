class Solution {
public:
      int findPossible(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
      if(ind>=nums.size()){
         if(target==0)return 1;
         return 0;
      }
      if(dp[ind][target]!=-1)return dp[ind][target];
      int take=0,ntake=0;
      if(target>=nums[ind]){
         take=findPossible(0,nums,target-nums[ind],dp);
      }
         ntake=findPossible(ind+1,nums,target,dp);
    
        return dp[ind][target]=take+ntake;
}
	int combinationSum4(vector<int>& nums, int target) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
      return findPossible(0,nums,target,dp);
	}
};


