class Solution {
public:
    bool ifMatched(int ind1,int ind2,string &str1,string &str2,vector<vector<int>>&dp){
       if(ind1<0&&ind2<0)return true;
       if(ind2<0)return false;
       if(ind1<0){
           for(int i=0;i<=ind2;i++){
               if(str2[i]!='*')return false;
           }
           return true;
       } 
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        
        if(str1[ind1]==str2[ind2]||str2[ind2]=='?'){
            return dp[ind1][ind2]=ifMatched(ind1-1,ind2-1,str1,str2,dp);
        }
        
        if(str2[ind2]=='*'){
            return dp[ind1][ind2]=ifMatched(ind1,ind2-1,str1,str2,dp)|ifMatched(ind1-1,ind2,str1,str2,dp);
            // for(int i=ind1;i>=-1;i--){
                // if(ifMatched(i,ind2-1,str1,str2,dp))return dp[ind1][ind2]=true;
            // }
        }
        
        return dp[ind1][ind2]=false;
        
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return ifMatched(n-1,m-1,s,p,dp);
    }
};