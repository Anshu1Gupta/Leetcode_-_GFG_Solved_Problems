class Solution {
    
public:
bool isPossible(int limit, vector<int>&arr,int max_sub){
   int sub=1;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>limit)return false;
        else if(arr[i]+sum<=limit){
            sum+=arr[i];
        }
        else{
            sum=arr[i];
            sub++;
        }
    }
    
    if(sub<=max_sub)return true;
    return false;
}
    int splitArray(vector<int>& nums, int k) {
     int low=*max_element(nums.begin(),nums.end());
     int high=0;
        for(int i=0;i<nums.size();i++)high+=nums[i];
        
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
};