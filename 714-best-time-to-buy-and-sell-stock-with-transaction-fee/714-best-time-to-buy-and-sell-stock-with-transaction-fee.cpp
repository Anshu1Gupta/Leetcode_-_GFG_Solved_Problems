class Solution {
public:
    int maxprofit(int choice,int ind,vector<int>&prices,int fee,vector<vector<int>>&dp){
        if(ind>=prices.size())return 0;
       
        if(dp[ind][choice]!=-1)return dp[ind][choice];
        int take=0,ntake=0;
        if(choice==1){    
             
            take=-1*prices[ind]+maxprofit(0,ind+1,prices,fee,dp);
            ntake=0+maxprofit(1,ind+1,prices,fee,dp);
            return dp[ind][choice]=max(take,ntake);
        }
        else{
            
            take=prices[ind]-fee+maxprofit(1,ind+1,prices,fee,dp);
            ntake=0+maxprofit(0,ind+1,prices,fee,dp);
            return dp[ind][choice]=max(take,ntake);
        }
       
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return maxprofit(1,0,prices,fee,dp);
    }
};