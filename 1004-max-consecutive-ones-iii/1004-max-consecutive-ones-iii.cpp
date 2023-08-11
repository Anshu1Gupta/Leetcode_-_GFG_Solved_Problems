class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int start=0;
        int end=0;
        
        int ans=0;
        int n=nums.size();
        while(end<n){
            
            if(nums[end]==0)k--;
            
            if(k<0){
                while(nums[start]!=0){
                    start++;
                }
                start++;
                k=0;
            }
            
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};