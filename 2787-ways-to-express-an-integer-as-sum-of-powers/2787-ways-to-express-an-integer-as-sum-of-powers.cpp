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
        
      vector<vector<long long >>dp(300+10,vector<long long >(300+10,-1));
      return maxNo(1,n,x,dp);
    }
};
// class Solution {
// public:
//     int MOD=(int)(1e9+7);
    
//     int findWays(int index,int num,int x,vector<vector<int>>&dp){
//         if(index<0) return 0;
//         if(index==0) return 1;
//         if(pow(num,x)>index) return 0;
//         if(dp[index][num]!=-1) return dp[index][num];
        
//         int temp=pow(num,x);
        
//         int notTaken=findWays(index-temp,num+1,x,dp);
//         int taken=findWays(index,num+1,x,dp);
        
//         return dp[index][num]=(notTaken%MOD+taken%MOD)%MOD;
//     }
    
//     int numberOfWays(int n, int x) {
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return findWays(n,1,x,dp);
//     }
// };