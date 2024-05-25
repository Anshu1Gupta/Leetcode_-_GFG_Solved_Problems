class Solution {
public:
    void findArr(int ind, string &str,vector<string>&ans,string &temp, unordered_map<string,int>&mp){
        if(ind>=str.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int end=ind+1;end<=str.size();end++){
            string s=str.substr(ind,end-ind);
            
            if(mp.find(s)!=mp.end()){
                string prev = temp.empty() ? s : (temp + " " + s);
                findArr(end,str,ans,prev,mp);
            }
        }
        
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string str;
        string temp;
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        findArr(0,s,ans,str,mp);
        
        return ans;
        
    }
};