class Solution {
public:
  void findSets(int i,vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums){
          if(i>=nums.size()){
              ans.push_back(temp);
              return;
          }
      temp.push_back(nums[i]);
      findSets(i+1,ans,temp,nums);
      temp.pop_back();
      findSets(i+1,ans,temp,nums);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        findSets(0,ans,temp,nums);
        return ans;
    }
};