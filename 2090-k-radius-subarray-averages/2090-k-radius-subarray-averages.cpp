class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size();
        long long start=0;
        long long end=2*k;
        if(k==0)return nums;
        if(2*k+1>n){
            vector<int>ans(n,-1);
            return ans;
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
           ans.push_back(-1);
        }
       long long sum=0;
        for(int i=0;i<=2*k;i++){
            sum=sum+nums[i];
        }
        long long div=(2*k+1);
        ans.push_back(sum/div);
        
        end++;
        while(end<n){
           
            sum-=nums[start++];
            sum+=nums[end];
            ans.push_back(sum/div);
            end++;
        }
        for(long long i=ans.size();i<nums.size();i++){
            ans.push_back(-1);
        }
        return ans;
    }
};