class Solution {
public:
    int longest(int ind1,int ind2,string &str1,string &str2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]=1+longest(ind1-1,ind2-1,str1,str2,dp);
        }
        
        int step1=longest(ind1-1,ind2,str1,str2,dp);
        int step2=longest(ind1,ind2-1,str1,str2,dp);
        
        return dp[ind1][ind2]=max(step1,step2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return longest(n-1,m-1,text1,text2,dp);
    }
};