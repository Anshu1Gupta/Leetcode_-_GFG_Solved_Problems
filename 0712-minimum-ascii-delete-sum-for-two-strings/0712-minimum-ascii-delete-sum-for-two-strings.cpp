class Solution {
public:
    int minValue(int ind1,int ind2,string &str1,string &str2,int n,int m,vector<vector<int>>&dp){
        int sum=0;
        if(ind1<0){
                int x=ind2;
            while(x>=0){
                sum+=str2[x];
                x--;
            }
            return sum;
        }
        if(ind2<0){
                int x=ind1;
            while(x>=0){
                sum+=str1[x];
                x--;
            }
            return sum;
        }
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(str1[ind1]==str2[ind2]){
            return dp[ind1][ind2]= 0+minValue(ind1-1,ind2-1,str1,str2,n,m,dp);
        }
        
        int take1=str1[ind1]+minValue(ind1-1,ind2,str1,str2,n,m,dp);
        int take2=str2[ind2]+minValue(ind1,ind2-1,str1,str2,n,m,dp);
        // int take3=str1[ind1]+str2[ind2]+minValue(ind1-1,ind2-1,str1,str2,n,m,dp);
        
        return dp[ind1][ind2]=min({take1,take2});
        
        
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minValue(n-1,m-1,s1,s2,n,m,dp);
    }
};