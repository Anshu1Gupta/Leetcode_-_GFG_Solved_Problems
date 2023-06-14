class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;                                                       
                                                                
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long remain=(long long)target-(long long)(nums[i]+nums[j]);
                int low=j+1,high=nums.size()-1;
                while(low<high){
                    long long sum=(long long)(nums[low]+nums[high]);
                    if(sum>remain)high--;
                    else if(sum<remain)low++;
                    
                    else{
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        
                        int temp1=low,temp2=high;
                        while(low<high&&nums[low]==nums[temp1])low++;
                        while(low<high&&nums[temp2]==nums[high])high--;
                    }
                    
                }
            while(j<(nums.size()-1)&&nums[j]==nums[j+1])j++;
            }
            while(i<(nums.size()-1)&&nums[i]==nums[i+1])i++;
        }
           
                      
     return ans;
                                                                
    }
};