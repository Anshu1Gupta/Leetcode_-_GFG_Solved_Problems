class Solution {
public:
    bool isMatched(int ind1,int ind2,string &str1,string &str2,vector<vector<int>>&dp){
        if(ind1<0&&ind2<0)return true;
        if(ind1<0){
            if(str2[ind2]=='*')return isMatched(ind1,ind2-2,str1,str2,dp);
            return false;
        }
        if(ind2<0)return false;
        
        if(str1[ind1]==str2[ind2]||str2[ind2]=='.'){
            return dp[ind1][ind2]=isMatched(ind1-1,ind2-1,str1,str2,dp);
        }
        bool take=false;
         if(str2[ind2]=='*'){
           
              if(str1[ind1]==str2[ind2-1]||str2[ind2-1]=='.'){
                  take=take|isMatched(ind1-1,ind2,str1,str2,dp);
              }
              return take| isMatched(ind1,ind2-2,str1,str2,dp);
              }
        
    return dp[ind1][ind2]=take;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return isMatched(n-1,m-1,s,p,dp);
    }
};