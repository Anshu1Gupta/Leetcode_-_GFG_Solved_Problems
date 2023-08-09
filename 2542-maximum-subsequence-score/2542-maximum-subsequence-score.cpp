class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>pair;
        int n=nums2.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pair.push_back({nums2[i],nums1[i]});
        }
        
        sort(pair.begin(),pair.end());
        long long ans=0;
        long long  sum=0;
        for(int i=n-1;i>(n-1-k);i--){
            pq.push(pair[i].second);
            sum+=pair[i].second;
        }
       
        long long val=sum*pair[n-k].first;
        ans=max(ans,val);
      
        int end=n-1-k;
        
        while(end>=0){
            int ele=pq.top();pq.pop();
            sum-=ele;
            sum+=pair[end].second;
            pq.push(pair[end].second);
            
            long long val=sum*pair[end].first;
            ans=max(ans,val);
            
            
            end--;
        }
        return ans;
        
    }
};