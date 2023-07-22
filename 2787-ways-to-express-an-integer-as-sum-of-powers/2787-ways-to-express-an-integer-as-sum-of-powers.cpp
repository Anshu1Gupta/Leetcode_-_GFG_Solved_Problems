class Solution {
public:
    int mod=1e9+7;
    long long  maxNo(long long  ind,long long  target,long long  p,vector<vector<long long >>&dp){
        if(target<0)return 0;
        if(target==0)return 1;
        
        long long  power=pow(ind,p);
        if(power>target)return 0;
        
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        
        
        long long take=0;
        if(power<=target){
            take=maxNo(ind+1,target-power,p,dp)%mod;
        }
        long long ntake=maxNo(ind+1,target,p,dp)%mod;
        
        
        if(target>=0)
        return dp[ind][target]=(take%mod+ntake%mod)%mod;
        
        return 0;
    }
    int numberOfWays(int n, int x) {
        
      vector<vector<long long >>dp(301,vector<long long >(300+10,-1));
      return maxNo(1,n,x,dp);
    }
};
