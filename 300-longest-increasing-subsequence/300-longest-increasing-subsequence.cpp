class Solution {
public:
    int maximum(int back,int i,vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[back+1][i]!=-1)return dp[back+1][i];
        int take=0;
        if(back==-1||nums[back]<nums[i]){
            take=1+maximum(i,i+1,nums,dp);
        }
        int ntake=0+maximum(back,i+1,nums,dp);
        
        return dp[back+1][i]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+1,-1));
        return maximum(-1,0,nums,dp);
    }
};