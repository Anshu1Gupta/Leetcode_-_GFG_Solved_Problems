class Solution {
public:
    bool ifPossible(int ind1,int ind2,string &str1,string &str2,string &str3,vector<vector<int>>&dp){
        if(ind1+ind2==str3.size()){return true;}
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
      bool ans=false;
        if(ind1<str1.size()&&str1[ind1]==str3[ind1+ind2]){
            ans=(ans|ifPossible(ind1+1,ind2,str1,str2,str3,dp));
        }
        if(ind2<str2.size()&&str2[ind2]==str3[ind1+ind2]){
            ans=(ans|ifPossible(ind1,ind2+1,str1,str2,str3,dp));
        }
        
        return dp[ind1][ind2]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        
        int n1=s1.length();
        int n2=s2.length();
        if(n1+n2!=s3.size())return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return ifPossible(0,0,s1,s2,s3,dp);
    }
};