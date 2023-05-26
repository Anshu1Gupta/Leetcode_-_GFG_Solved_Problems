class Solution {
public:
    void nways(int i,int target,vector<int>& nums,vector<int>&temp,set<vector<int>>&set){
        if(i<0){
            if(target==0){
                set.insert(temp);
               
            }
             return ;
        }
        if(target>=nums[i]){
          temp.push_back(nums[i]);
            nways(i,target-nums[i],nums,temp,set);
            temp.pop_back();
        }
        nways(i-1,target,nums,temp,set);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
        set<vector<int>>set;
        vector<int>temp;
        sort(candidates.begin(),candidates.end(),greater<>());
        nways(n-1,target,candidates,temp,set);
        for(auto it:set){
            ans.push_back(it);
        }
        return ans;
    }
};