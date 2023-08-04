class Solution {
public:
    void findCombination(int ind,vector<int>&nums,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)return ;
        
        for(int i=ind;i<nums.size();i++){
            if(i>ind&&nums[i]==nums[i-1])continue;
                temp.push_back(nums[i]);
                findCombination(i+1,nums,target-nums[i],temp,ans);
                temp.pop_back();
            
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        // vector<int>arr;
       
        // int n=candidates.size();
        findCombination(0,candidates,target,temp,ans);
        return ans;
    }
};