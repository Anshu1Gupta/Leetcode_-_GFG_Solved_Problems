class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        unordered_set<int>set;
        for(auto it:matches){
            mp[it[1]]++;
            set.insert(it[0]);
            set.insert(it[1]);
        }
        vector<int>zero,one;
        vector<vector<int>>ans;
        
        for(auto it:set){
            if(mp[it]==1)one.push_back(it);
        }
        for(auto it:set){
            if(mp[it]==0)zero.push_back(it);
        }
        
      // for(auto it:zero){
      //     cout<<it<<endl;
      // }
      // for(auto it:one){
      //     cout<<it<<endl;
      // }
      
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
          ans.push_back(zero);
        ans.push_back(one);
        return ans;
    }
};