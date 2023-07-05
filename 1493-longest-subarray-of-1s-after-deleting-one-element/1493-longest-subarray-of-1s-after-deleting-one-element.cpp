class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=0,i=0,j=0,count=0, ans=0;
        while(j<nums.size()){
            
            if(nums[j]==0)count++;
            if(count==2){
                while(nums[i]!=0){
                    i++;
                }
                i++;
                count=1;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans-1;

    }
};
