class Solution {
public:
    bool ifSegmented(int ind,string &str,unordered_set<string>&set,vector<int>&dp){
        if(ind>=str.size())return true;
        
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<str.size();i++){
            if(set.find(str.substr(ind,i-ind+1))!=set.end()){
                if(ifSegmented(i+1,str,set,dp))return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string>set;
        for(auto it:wordDict){
            set.insert(it);
        }
        int n=s.length();
        vector<int>dp(n+1,-1);
        return ifSegmented(0,s,set,dp);
    }
};