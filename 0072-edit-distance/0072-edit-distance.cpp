class Solution {
public:
    int mini(int ind1,int ind2,string&str1,string&str2,vector<vector<int>>&dp){
        if(ind1<0&&ind2<0)return 0;
        if(ind1<0)return ind2+1;
        if(ind2<0)return ind1+1;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]=0+mini(ind1-1,ind2-1,str1,str2,dp);
        }
        else{
            int t1=mini(ind1-1,ind2,str1,str2,dp);
            int t2=mini(ind1-1,ind2-1,str1,str2,dp);
            int t3=mini(ind1,ind2-1,str1,str2,dp);
            return dp[ind1][ind2]=1+min({t1,t2,t3});
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return mini(n-1,m-1,word1,word2,dp);
        
    }
};