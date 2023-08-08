class Solution {
    
public:
    int mini(int ind,vector<int>&cost,vector<int>&dp){
        if(ind>=cost.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int take1=cost[ind]+mini(ind+1,cost,dp);
        int take2=cost[ind]+mini(ind+2,cost,dp);
        
        return dp[ind]=min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(mini(0,cost,dp),mini(1,cost,dp));
    }
};