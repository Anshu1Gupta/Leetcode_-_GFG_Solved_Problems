class Solution {
public:
    int findPart(int ind,vector<int>&rods,int diff,vector<vector<int>>&dp){
        if(ind>=rods.size()){
           if(diff==5000)return 0;
            
            else
            return INT_MIN;;
        }
       if(dp[ind][diff]!=INT_MIN)return dp[ind][diff];
        
       int ans1=findPart(ind+1,rods,diff,dp);
       int ans2=findPart(ind+1,rods,diff-rods[ind],dp);
       int ans3=rods[ind]+findPart(ind+1,rods,diff+rods[ind],dp);
        
       return dp[ind][diff]=max({ans1,ans2,ans3});
        
    }
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(rods.size(),vector<int>(10001,INT_MIN));
        int ans=findPart(0,rods,5000,dp);
        return ans;
    }
};
