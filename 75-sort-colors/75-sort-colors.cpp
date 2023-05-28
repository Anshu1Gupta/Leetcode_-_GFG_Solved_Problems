class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count0++;
            if(nums[i]==1)count1++;
            if(nums[i]==2)count2++;
            
        }
        for(int i=0;i<nums.size();i++){
            if(count0){
                count0--;nums[i]=0;continue;
            }
            if(count1){
                count1--;nums[i]=1;continue;
            }
            if(count2){
                count2--;nums[i]=2;continue;
            }
        }
    }
};