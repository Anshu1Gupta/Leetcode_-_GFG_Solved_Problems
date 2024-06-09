class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
         sum=((sum+nums[i])%k+k)%k;
            
            count+=mp[sum];
            mp[sum]++;
        }
        return count;
    }
};