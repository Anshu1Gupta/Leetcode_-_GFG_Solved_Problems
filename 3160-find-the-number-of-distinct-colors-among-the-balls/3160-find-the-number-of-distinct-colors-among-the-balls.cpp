class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>fre;
        
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            
            int prev=mp[x];
            fre[y]++;
            fre[prev]--;
            
            if(fre[prev]<=0)fre.erase(prev);
            mp[x]=y;
            
            
            ans.push_back(fre.size());
        }
        
        return ans;
        
        
    }
};