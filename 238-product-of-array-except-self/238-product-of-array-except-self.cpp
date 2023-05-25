class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long sum=1;
        int count=0;
        long long wsum=1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
            count++;
           }
            sum=sum*nums[i];
            if(nums[i]!=0)
            wsum=wsum*nums[i];
        }
        int n=nums.size();
        vector<int>ans(n,0);
        if(count>=2)return ans;
        else{
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    ans[i]=sum/nums[i];
                }
                else{
                    ans[i]=wsum;
                }
            }
        }
        return ans;
        
    }
};