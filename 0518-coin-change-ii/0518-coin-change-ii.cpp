class Solution {
public:
    int nways(int ind,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(ind==0){
            return target%coins[ind]==0;
        }
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        int take=0;
        if(target>=coins[ind]){
            take=nways(ind,coins,target-coins[ind],dp);
        }
        int ntake=nways(ind-1,coins,target,dp);
        
        return dp[ind][target]=take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return nways(n-1,coins,amount,dp);
        
    }
};