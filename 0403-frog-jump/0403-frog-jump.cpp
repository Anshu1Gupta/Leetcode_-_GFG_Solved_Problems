class Solution {
public:
    bool ifPossible(int ind,int prev,vector<int>&stones,vector<vector<int>>&dp){
        if(ind==stones.size()-1)return true;
        
        if(dp[ind][prev]!=-1)return dp[ind][prev];
        int k=stones[ind]-stones[prev];
        
        for(int j=ind+1;j<stones.size();j++){
            int diff=stones[j]-stones[ind];
            if(abs(diff-k)<=1){
                if(ifPossible(j,ind,stones,dp)){
                    return dp[ind][prev]=true;
                }
            }
        }
        
        return dp[ind][prev]= false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(stones[1]-stones[0]!=1)return false;
        return ifPossible(1,0,stones,dp);
    }
};