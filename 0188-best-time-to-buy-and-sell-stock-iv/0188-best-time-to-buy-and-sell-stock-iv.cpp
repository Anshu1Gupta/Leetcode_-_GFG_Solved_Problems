class Solution {
public:
    int maxiProfit(int ind,int k,int turn,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(k==0)return 0;
        if(ind>=prices.size())return 0;
        
        if(dp[ind][turn][k]!=-1)return dp[ind][turn][k];
        if(turn==0){
            int take=-prices[ind]+maxiProfit(ind+1,k,!turn,prices,dp);
            int ntake=0+maxiProfit(ind+1,k,turn,prices,dp);
            
            return dp[ind][turn][k]=max(take,ntake);
        }
        else{
            int take=prices[ind]+maxiProfit(ind+1,k-1,!turn,prices,dp);
            int ntake=0+maxiProfit(ind+1,k,turn,prices,dp);
            return dp[ind][turn][k]=max(take,ntake);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int> > > dp(n+1, vector<vector<int>>(4, vector<int>(k+1, 0)));
        // return maxiProfit(0,k,0,prices,dp);
      
     
        for(int ind=n-1;ind>=0;ind--){
            for(int turn=0;turn<=1;turn++){
                for(int x=1;x<=k;x++){
                    
                    if(turn==0){
                         int take=-prices[ind]+dp[ind+1][!turn][x];
                         int ntake=0+dp[ind+1][turn][x];;
                        dp[ind][turn][x]=max(take,ntake);
                    }
                    else{
                        int take=prices[ind]+dp[ind+1][!turn][x-1];;
                         int ntake=0+dp[ind+1][turn][x];
                        dp[ind][turn][x]=max(take,ntake);
                    }
                }
            }
        }
        return dp[0][0][k];

      

    }
};