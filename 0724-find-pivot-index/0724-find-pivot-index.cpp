class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int tsum=0;
        for(int i=0;i<nums.size();i++){
            tsum+=nums[i];
        }
        
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            int rightSum=tsum-leftSum-nums[i];
            if(leftSum==rightSum)return i;
            
            leftSum+=nums[i];
        }
        return -1;
    }
};