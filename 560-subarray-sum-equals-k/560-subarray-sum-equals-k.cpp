class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int count=0;
        unordered_map<int,int>mp;
    
        for(int i=0;i<nums.size();i++){
            if(prefix[i]==k)count++;
            if(mp.find(prefix[i]-k)!=mp.end()){
            count+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};