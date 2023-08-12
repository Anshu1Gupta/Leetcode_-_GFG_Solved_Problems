class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low=nums[0];
        int mid=INT_MAX;
        
        int n=nums.size();
        for(int i=1;i<n;i++){
            
            if(nums[i]>mid)return true;
            
            if(nums[i]>low&&nums[i]<mid){
                mid=nums[i];
            }
            else if(nums[i]<low){
                low=nums[i];
            }
        }
        return false;
    }
};