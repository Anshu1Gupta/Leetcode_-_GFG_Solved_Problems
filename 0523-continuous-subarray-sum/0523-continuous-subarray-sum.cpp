class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        mp[0]=-1;
        
        int sum=0;
        
        
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            sum=sum%k;
            
            if(mp.find(sum)!=mp.end()){
                int len=i-mp[sum];
                if(len>1)return true;
            }
            else{
                mp[sum]=i;
            }
        }
        return false;
    }
};