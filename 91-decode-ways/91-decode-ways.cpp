class Solution {
    public:
    int res=0;
   int nways(int ind,string str,vector<int>&dp){
        if(ind==str.length()){
           return 1;
        }
      if(dp[ind]!=-1)return dp[ind];
      if(str[ind]=='0')return 0 ;
       
      int take=nways(ind+1,str,dp);
       int ntake=0;
      if(ind<str.size()-1&&(str[ind]=='1'||str[ind]=='2'&&str[ind+1]<='6'))
      ntake=nways(ind+2,str,dp);
      
       return dp[ind]=take+ntake;
        
    }
    int numDecodings(string str) {
        if(str[0]=='0')return 0;
        int n=str.length();
        vector<int>dp(n+1,-1);
       return  nways(0,str,dp);
       
    }
};