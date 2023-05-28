class Solution {
public:
    string longestPalindrome(string str) {
        int n=str.length();
        int ind1=0,ind2=0;
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(str[i]==str[i-1]){
                dp[i-1][i]=1;
                ind1=i-1;
                ind2=i;
            }
            dp[i][i]=1;
        }
       
        for(int i=1;i<n;i++){
            int q=0;
            int p=i;
            while(p<n){
                if(str[q]==str[p]&&dp[q+1][p-1]==1){
                    dp[q][p]=1;
                    ind1=q;
                    ind2=p;
                }
                p++;
                q++;
            }
        }
        
        string ans="";
        for(int i=ind1;i<=ind2;i++){
            ans=ans+str[i];
        }
        return ans;
        
        
        
    }
};