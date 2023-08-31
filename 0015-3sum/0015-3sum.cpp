class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int low=i+1;
            int high=n-1;
            int target=-nums[i];
            
            while(low<high){
               int val=nums[low]+nums[high];
                
                if(val<target){
                    low++;
                }
                else if(val>target){
                    high--;
                }
                else{
                    ans.push_back({nums[i],nums[low],nums[high]});
                    
                    int ind1=low,ind2=high;
                    while(low<high&&nums[ind1]==nums[low])low++;
                    while(low<high&&nums[ind2]==nums[high])high--;
                }
            }
        }
        return ans;
    }
};