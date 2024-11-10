class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>bitCounts(32,0);
        
        int l=0,r=0,mini=INT_MAX;
        int ans=0;
        int n=nums.size();
        while(r<n){
            ans=ans|nums[r];
            
            for(int i=0;i<32;i++){
                if(nums[r] & (1<<i)){
                  bitCounts[i]++;
                }
            }
            
            while(l<=r && ans>=k){
                mini=min(mini,r-l+1);
                for(int i=0;i<32;i++){
                    if(nums[l] & (1<<i)){
                      bitCounts[i]--;
                        
                        if(bitCounts[i]==0){
                        ans=ans-(1<<i);
                    }
                    }
                    
                    
                }
                l++;
            }
            r++;
            
        }
        return mini==INT_MAX?-1:mini;
    }
};