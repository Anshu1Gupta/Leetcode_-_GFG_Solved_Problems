class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e9;
        int i=0,j=0;
        int sum=0;
        while(j<nums.size()){
            
            
            sum+=nums[j];
            while(sum>=target&&i<=j){
                int len=j-i+1;
                ans=min(ans,len);
                sum-=nums[i];
                i++;
            }
            
            j++;
        }
        if(ans==1e9)return 0;
        return ans;
    }
};