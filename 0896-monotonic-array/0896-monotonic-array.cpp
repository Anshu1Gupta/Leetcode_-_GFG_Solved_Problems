class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return true;
        int inc=0;
        int dec=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1])dec++;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1])inc++;
        }
        
        if(inc==n-1||dec==n-1)return true;
        return false;;
    }
};