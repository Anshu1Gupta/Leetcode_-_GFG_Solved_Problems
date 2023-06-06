class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=nums[0];
        int mxr=nums[0];
        if(nums.size()==1)return true;
        if(steps==0)return false;
        
        for(int i=1;i<nums.size();i++){
            if(i==nums.size()-1)return true;
            
            mxr=max(mxr,nums[i]+i);
            steps--;
            if(steps==0){
                steps=mxr-i;
                if(steps<=0)return false;
            }
        }
        return true;
    }
};