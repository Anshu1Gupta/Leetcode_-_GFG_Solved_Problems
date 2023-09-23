class Solution {
public:
    bool static cmp(string &a,string &b){
        return a.length()<b.length();
    }
    
    bool checkPred(int prev,int ind,vector<string>&words){
        if(words[prev].size()+1!=words[ind].size())return false;
        string pr=words[prev];
        string af=words[ind];
        
        int maxi=af.size();
        
       int j=0;
       for(int i=0;i<maxi;i++){
           if(af[i]==pr[j])j++;
       }
        
        if(j==pr.size())return true;
        return false;
    }
    int longest(int prev,int ind,vector<string>&words,vector<vector<int>>&dp){
        
        if(ind>=words.size())return 0;
        int take=0;
        if(dp[prev+1][ind]!=-1)return dp[prev+1][ind];
        if(prev==-1||checkPred(prev,ind,words)){
            take=1+longest(ind,ind+1,words,dp);
        }
        int ntake=longest(prev,ind+1,words,dp);
        return dp[prev+1][ind]=max(take,ntake);
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        
        vector<vector<int>>dp(n+3,vector<int>(n+1,-1));
        return longest(-1,0,words,dp);
    }
};