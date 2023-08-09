class Solution {
public:
    bool canMakePairs(vector<int>&nums,int p,int maxi){
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=maxi){
                p--;i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)return 0;
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1]-nums[0];
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(canMakePairs(nums,p,mid))high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};