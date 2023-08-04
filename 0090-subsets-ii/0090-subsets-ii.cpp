class Solution {
public:
    void finSets(int ind,vector<int>&nums,vector<int>&temp,set<vector<int>>&ans){
        if(ind>=nums.size()){
            ans.insert(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        finSets(ind+1,nums,temp,ans);
        temp.pop_back();
        finSets(ind+1,nums,temp,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        set<vector<int>>ans;
        vector<vector<int>>result;
        finSets(0,nums,temp,ans);
        
        for(auto it:ans){
            result.push_back(it);
        }
        return result;
    }
};