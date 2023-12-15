class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
         unordered_map<string,int>mp;
         set<string>set;
         for(auto it:paths){
             mp[it[0]]++;
             set.insert(it[0]);
             set.insert(it[1]);
         }
        
        
        for(auto it:set){
            if(mp.find(it)==mp.end())return it;
        }
        return "";
        
        
    }
};