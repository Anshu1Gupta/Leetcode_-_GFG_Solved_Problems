class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        int n=nums.size();
        int start=0;
        int end=k;
        
        while(end<n){
           if(dq.front()==nums[start])dq.pop_front();
            
           while(!dq.empty()&&dq.back()<nums[end]){
               dq.pop_back();
           }
            dq.push_back(nums[end]);
            
            ans.push_back(dq.front());
            start++;
            end++;
        }
        return ans;
    }
};