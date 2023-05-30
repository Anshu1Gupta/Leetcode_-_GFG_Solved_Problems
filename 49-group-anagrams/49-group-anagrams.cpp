class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto it:strs){
            string ans=it;
            sort(ans.begin(),ans.end());
            mp[ans].push_back(it);
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};