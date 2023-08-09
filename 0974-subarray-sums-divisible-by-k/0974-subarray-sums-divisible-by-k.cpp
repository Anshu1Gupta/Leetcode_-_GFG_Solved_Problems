class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum=0;
        unordered_map<int,int>mp;
        
        // cout<<-10%5<<endl;
        mp[0]=1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=((sum+nums[i])%k+k)%k;

            
            count+=mp[sum];
            mp[sum]++;
            
        }
        return count;
        
    }
};