class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1=-1,ind2=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            ind1=i;break;
            }
        }
        if(ind1==-1){
            reverse(nums.begin(),nums.end());
           return;
        }
    
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[ind1]){
             swap(nums[i],nums[ind1]);
                break;
            }
        }
      reverse(nums.begin()+ind1+1,nums.end());
        
    }
};