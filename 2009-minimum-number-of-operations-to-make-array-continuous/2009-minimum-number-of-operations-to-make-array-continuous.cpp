class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>set;
        for(auto it:nums){
            set.insert(it);
        }
        int maxi=0;
        vector<int>ans;
        for(auto it:set){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        
        int right=0;
        
        int nS=ans.size();
        
        for(int left=0;left<n;left++){
            while(right<nS&&(ans[right]-ans[left]<=n-1))right++;
            
            int curr=right-left;
            maxi=max(maxi,curr);
        }
        return n-maxi;
    }
};