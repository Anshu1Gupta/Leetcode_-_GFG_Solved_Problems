class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int start=0,end=n-1;
        int count=0;
        while(start<end){
            int val=nums[start]+nums[end];
            if(val==k){
                count++;
                start++;end--;
            }
            else if(val<k)start++;
            else end--;
        }
        return count;
    }
};