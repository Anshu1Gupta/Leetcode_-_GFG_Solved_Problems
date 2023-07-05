class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int flag=0;
        int len=0;
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0){
                count++;
                flag=1;
            }
            
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
