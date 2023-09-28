class Solution {
public:
   void findPermutations(set<vector<int>>&ans,vector<int>&temp,vector<int>&visited,vector<int>&nums){
        
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i]=1;
                findPermutations(ans,temp,visited,nums);
                temp.pop_back();
                visited[i]=0;
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>set;
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>visited(n,0);
        findPermutations(set,temp,visited,nums);
        
        for(auto it:set){
            ans.push_back(it);
        }
        return ans;
    }
};