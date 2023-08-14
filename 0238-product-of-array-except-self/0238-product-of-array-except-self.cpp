class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suff(n),ans(n);
        
        int prod=1;
        for(int i=0;i<n;i++){
            pre[i]=prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            suff[i]=prod;
            prod*=nums[i];
        }
        
        for(int i=0;i<n;i++){
            ans[i]=suff[i]*pre[i];
        }
        return ans;
    }
};