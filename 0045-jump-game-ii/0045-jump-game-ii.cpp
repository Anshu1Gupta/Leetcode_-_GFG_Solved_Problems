class Solution {
public:
    
    int minimum(int ind,vector<int>&arr,vector<int>&dp){
    if(ind>=arr.size()-1)return 0;
    
    if(dp[ind]!=-1)return dp[ind];
    int maxi=10011;
    for(int i=1;i<=arr[ind];i++){
        maxi=min(maxi,1+minimum(ind+i,arr,dp));
    }
    return dp[ind]=maxi;
}
int jump(vector<int>& A) {
    int n=A.size();
    vector<int>dp(n+1,-1);
    int val= minimum(0,A,dp);
    if(val==INT_MAX)return -1;
    return val;
}
   
    
};