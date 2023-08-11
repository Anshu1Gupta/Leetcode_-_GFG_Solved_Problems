class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int start=0;
        int end=0;
        int flag=1;
        int ans=0;
        int n=nums.size();
        while(end<n){
            
            if(nums[end]==0){
                if(flag==0){
                    while(nums[start]!=0){
                        start++;
                    }
                    start++;
                }
                flag=0;
                
            }
            
            ans=max(ans,end-start+1);
            end++;
        }
        // ans=max(ans,end-start+1);
       ans--;
        
        return ans;
    }
};