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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return longest(n-1,m-1,text1,text2,dp);
        
        // for(int ind1=0;ind1<n;ind1++)dp[ind1][0];
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else
                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
};