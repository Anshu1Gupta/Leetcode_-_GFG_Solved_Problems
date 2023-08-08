class Solution {
public:
    int maxP(int ind,int ch,vector<int>&prices,int fee,vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;
        if(dp[ind][ch]!=-1)return dp[ind][ch];
        if(ch==0){
            int take=-prices[ind]+maxP(ind+1,1,prices,fee,dp);
            int ntake=0+maxP(ind+1,0,prices,fee,dp);
            
            return dp[ind][ch]=max(take,ntake);
        }
        else{
            int take= prices[ind]+maxP(ind+1,0,prices,fee,dp)-fee;
            int ntake= 0+maxP(ind+1,1,prices,fee,dp);
            
            return dp[ind][ch]=max(take,ntake);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return maxP(0,0,prices,fee,dp);
    }
};