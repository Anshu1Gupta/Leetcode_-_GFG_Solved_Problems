class Solution {
public:
    int mod=1e9+7;
    int numTilings(int n) {
        
        if(n==1)return 1;
        if(n==2)return 2;
        
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=((dp[i-1]*2)%mod+dp[i-3]%mod)%mod;
            cout<<i<<' '<<dp[i]<<endl;
        }
        return dp[n];
    }
};