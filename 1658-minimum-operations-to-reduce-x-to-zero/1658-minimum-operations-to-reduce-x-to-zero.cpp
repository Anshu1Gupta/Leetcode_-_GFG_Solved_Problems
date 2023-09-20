class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        unordered_map<int,int>mp;
        mp[0]=-1;
        int temp=0;
        int target=sum-x;
        int maxi=-1;
        
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            
            if(mp.find(temp-target)!=mp.end()){
                int  length=(i-mp[temp-target]);
                maxi=max(length,maxi);
            }
            
            if(mp.find(temp)==mp.end()){
                mp[temp]=i;
            }
        }
        
        
        int n=nums.size();
        if(target==0)return n;
        if(maxi==-1)return -1;
        return n-maxi;
    }
};