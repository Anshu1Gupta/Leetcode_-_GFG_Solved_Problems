class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low=1;
        int high=nums.size()-1;
        // int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid-1]>=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return high;
    }
};