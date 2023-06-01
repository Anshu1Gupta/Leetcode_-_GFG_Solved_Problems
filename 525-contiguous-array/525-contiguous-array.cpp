class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int length=0;
        for(int i=0;i<nums.size();i++){
           sum += nums[i] == 0 ? - 1 : 1;
            if(mp.find(sum)!=mp.end()){
                if(length<(i-mp[sum])){
                    length=i-mp[sum];
                }
                
            }
            else{
                mp[sum]=i;
            }
            
        }
        return length;
    }
};