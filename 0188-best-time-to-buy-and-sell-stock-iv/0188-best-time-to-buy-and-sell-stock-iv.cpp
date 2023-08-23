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
       vector<vector<vector<int> > > dp(n+1, vector<vector<int>>(4, vector<int>(k+1, -1)));
        return maxiProfit(0,k,0,prices,dp);
    }
};