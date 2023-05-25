class Solution {
public:
    int mini(int i,int target,vector<int>&coins,vector<vector<int>>&dp){

if(i==0){
if(target==0||target%coins[0]==0)return target/coins[0];
    return 1e9;
}
        if(dp[i][target]!=-1)return dp[i][target];
int take=1e9;
if(target>=coins[i]){
take=1+mini(i,target-coins[i],coins,dp);
}
int ntake=mini(i-1,target,coins,dp);
        return dp[i][target]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int sol=mini(n,amount,coins,dp);
        if(sol==1e9)return -1;
        return sol;
    }
};