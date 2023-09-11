class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            
            int size=it.first;
            vector<int>temp;
            while(it.second.size()!=0){
                temp.push_back(it.second.back());
                it.second.pop_back();
                if(temp.size()==size){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
            
        }
        return ans;
    }
};