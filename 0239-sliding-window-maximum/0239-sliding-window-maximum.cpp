class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        
        for(int i=0;i<k;i++){
            while(!q.empty()&&nums[i]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        vector<int>ans;
        ans.push_back(q.front());
        int end=k;
        int start=0;
        
        while(end<n){
            if(nums[start]==q.front())q.pop_front();
            start++;
            while(!q.empty()&&nums[end]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[end]);
            ans.push_back(q.front());
            end++;
        }
        return ans;
    }
};