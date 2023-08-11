class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int start=0;
        int end=0;
        
        int n=nums.size();
        while(end<n){
            if(nums[end]!=0){
                swap(nums[start],nums[end]);
                start++;
            }
            end++;
        }
    }
};