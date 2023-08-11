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
        
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        int target=amount;
        // return nways(n-1,coins,amount,dp);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int take=0;
                if(j>=coins[i]){
                    take=dp[i][j-coins[i]];
                }
                int ntake=dp[i-1][j];
                
                dp[i][j]=take+ntake;
            }
        }
        return dp[n-1][target];
        
    }
};