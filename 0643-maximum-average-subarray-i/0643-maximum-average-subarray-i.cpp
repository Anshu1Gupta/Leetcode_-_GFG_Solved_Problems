class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-1e9;
        double average=0;
        
        for(int i=0;i<k;i++)average+=nums[i];
        
        int start=0;
        int end=k;
        int n=nums.size();
        ans=max(ans,average/(k*1.0));
        while(end<n){
            average-=nums[start++];
            average+=nums[end++];
            
            ans=max(ans,average/(k*1.0));
        }
        return ans;
        
    }
};