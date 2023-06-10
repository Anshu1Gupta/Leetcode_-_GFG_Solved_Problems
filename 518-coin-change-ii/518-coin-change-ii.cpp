class Solution {
public:
  int mod=1e9+7;
long long nways(long long n,long long target,vector<int>&arr,vector<vector<long long>>&dp){
   if(n==0){
        if(target==0||target%arr[n]==0)return 1;
        else return 0;
   }
   if(dp[n][target]!=-1)return dp[n][target];
   long long take=0;
   if(arr[n]<=target){
       take=nways(n,target-arr[n],arr,dp);
   }
   long long ntake=nways(n-1,target,arr,dp);
   return dp[n][target]=take+ntake;
    
}
    int change(int sum, vector<int>& coins) {
int N=coins.size();
      vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
           return nways(N-1,sum,coins,dp);
    }
    
        
    
};