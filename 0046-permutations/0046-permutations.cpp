class Solution {
public:
void permute(vector<int>&nums,vector<vector<int>>&ans,
             vector<int>&temp,vector<int>&visited){
    
    
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!visited[i]){
                visited[i]=1;
                temp.push_back(nums[i]);
                permute(nums,ans,temp,visited);
                temp.pop_back();
                visited[i]=0;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        vector<int>visited(n,0);
        permute(nums,ans,temp,visited);
        return ans;
        
    }
};