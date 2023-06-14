class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>set;                                                        
                                                                
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long remain=(long long)target-(long long)(nums[i]+nums[j]);
                int low=j+1,high=nums.size()-1;
                while(low<high){
                    long long sum=(long long)(nums[low]+nums[high]);
                    if(sum==remain){
                        set.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++,high--;
                    }
                    else if(sum>remain){
                        high--;
                    }
                    else{
                        low++;
                    }
                    
                }
            }
        }
            vector<vector<int>>ans;
        for(auto it:set){
            ans.push_back(it);
        }
                              
     return ans;
                                                                
    }
};