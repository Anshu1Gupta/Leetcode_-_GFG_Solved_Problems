class Solution {
public:
    bool isExist(int i,string str,unordered_set<string>&Dict,vector<int>&dp){
        if(i>=str.length()){
         return true;
        }
        if(dp[i]!=-1)return dp[i];
        string temp;
        for(int j=i;j<str.length();j++){
            temp+=str[j];
            if(Dict.find(temp)!=Dict.end()){
               if(isExist(j+1,str,Dict,dp)){
                   return dp[i]=true;
               }
            }
        }
        return dp[i]=false;
        
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string>Dict;
        for(auto it:wordDict){
            Dict.insert(it);
        }
        int n=str.length();
        vector<int>dp(n+1,-1);
        return isExist(0,str,Dict,dp);
    }
};