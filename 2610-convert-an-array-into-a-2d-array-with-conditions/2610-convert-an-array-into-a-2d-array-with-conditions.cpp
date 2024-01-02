class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=-1;
        for(auto it:nums){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        
        vector<vector<int>>ans;
        int size=maxi;
        while(size--){
            vector<int>small;
            
            for(auto it:mp){
                if(it.second!=0){
                    small.push_back(it.first);
                    mp[it.first]--;
                }
            }
            ans.push_back(small);
        }
        
//         vector<int>small;
//         vector<vector<int>>ans;
//         int flag=0;
//         while(mp.size()){
            
//             for(auto it:mp){
//               if(it.second!=0){
//                     small.push_back(it.first);
//                     it.second--;
//                   flag=1;
//                 }
//             }
//             if(flag==0)break;
            
//             ans.push_back(small);
//         }
        return ans;
    }
};