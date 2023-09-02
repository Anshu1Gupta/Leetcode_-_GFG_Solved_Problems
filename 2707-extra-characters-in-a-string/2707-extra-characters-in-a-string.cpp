class Solution {
public:
    unordered_set<string>map;
    int n;
    
    int minEx(int ind,string &str,vector<int>&dp){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int minExtra=n;
        string temp="";
        
        for(int i=ind;i<n;i++){
            temp.push_back(str[i]);
            
            int extra=map.find(temp)==map.end()?temp.size():0;
            int nextExtra=minEx(i+1,str,dp);
            int totalExtra=extra+nextExtra;
            
            minExtra=min(minExtra,totalExtra);
        }
        
        return dp[ind]=minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       n=s.length();
       for(auto it:dictionary){
           map.insert(it);
       } 
        vector<int>dp(n+1,-1);
       return minEx(0,s,dp);
    }
};