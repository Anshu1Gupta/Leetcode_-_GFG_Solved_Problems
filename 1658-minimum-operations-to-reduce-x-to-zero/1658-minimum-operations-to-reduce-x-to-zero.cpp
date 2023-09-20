class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target=sum-x;
        if(target==0)return nums.size();
        if(target<0)return -1;
        int miniOp=INT_MAX;
        int left=0;
        int right=0;
        
        int currSum=0;
        int n=nums.size();
        while(right<n){
            currSum+=nums[right];
            while(currSum>target){
                currSum-=nums[left];
                left++;
            }
            if(currSum==target){
                int length=right-left+1;
                miniOp=min(miniOp,n-length);
            }
            right++;
        }
        
        if(miniOp==INT_MAX)return -1;
        return miniOp;
        
        
        
    }
};