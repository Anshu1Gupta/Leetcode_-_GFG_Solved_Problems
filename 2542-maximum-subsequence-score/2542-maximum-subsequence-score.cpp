class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>dir;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            dir.push_back({nums2[i],nums1[i]});
        }
        
        sort(dir.begin(),dir.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=n-1;i>(n-1-k);i--){
            sum+=dir[i].second;
            pq.push(dir[i].second);
        }
        
        long long ans=0;
        long long val=sum*dir[n-k].first;
        
        ans=max(ans,val);
        int end=n-1-k;
        while(end>=0){
            int mini=pq.top();pq.pop();
            sum-=mini;
            sum+=dir[end].second;
            val=sum*dir[end].first;
            pq.push(dir[end].second);
            ans=max(ans,val);
            end--;
        }
        return ans;
    }
};

// 1 2 3 4  5 6 7 8 9
// 0 1 2 3  4 5 6 7 8