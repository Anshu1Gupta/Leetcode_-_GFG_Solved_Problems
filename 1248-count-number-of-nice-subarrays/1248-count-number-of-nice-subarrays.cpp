class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)arr[i]=1;
            else arr[i]=0;
        }
        
        unordered_map<int,int>mp;
        mp[0]=1;
        
        int rsum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            rsum+=arr[i];
            
            int diff=rsum-k;
            ans+=mp[diff];
            
            mp[rsum]++;
        }
        return ans;
    }
};