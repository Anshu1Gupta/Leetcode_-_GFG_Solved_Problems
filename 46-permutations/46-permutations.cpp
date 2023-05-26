class Solution {
public:
void nways(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,vector<int>&visited){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i]=1;
                nways(nums,temp,ans,visited);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>visited(n,0);
        nways(nums,temp,ans,visited);
        return ans;
    }
};