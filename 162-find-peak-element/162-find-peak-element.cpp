class Solution {
public:
    int ans=-1;
    void peak(vector<int>&nums,int low,int high){
        
        if(low<=high){
            int mid=(low+high)/2;
            
         if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                ans=mid;
                return ;
            }
        
        
        peak(nums,low,mid-1);
        peak(nums,mid+1,high);
            
            // return;
        }
        return;
    }
    int findPeakElement(vector<int>& nums) {
        peak(nums,0,nums.size()-1);
        
        return ans;
    }
};