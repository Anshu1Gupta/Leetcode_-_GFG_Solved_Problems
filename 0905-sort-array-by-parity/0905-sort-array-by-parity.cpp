class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        
        int fir=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                while(fir<i&&nums[fir]%2==0)fir++;
                if(fir<n)swap(nums[i],nums[fir]);
            }
            
           
        }
        return nums;
    }
};