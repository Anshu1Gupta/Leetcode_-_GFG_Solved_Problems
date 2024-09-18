class Solution {
public:
    void findAll(int ind,vector<int>&nums,set<vector<int>>&ans,vector<int>&temp){
        if(ind>=nums.size()){
            ans.insert(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        findAll(ind+1,nums,ans,temp);
        temp.pop_back();
        findAll(ind+1,nums,ans,temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<vector<int>>res;
        vector<int>temp;
        findAll(0,nums,ans,temp);
        for(auto it:ans){
            res.push_back(it);
        }
        return res;
    }
};