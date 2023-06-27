class Solution {
public:
    struct comp{
        char operator()(pair<int,int> &x,pair<int,int> &y){
         return y.first+y.second>x.first+x.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size()<k){
                    pq.push({nums1[i],nums2[j]});
                }
                else if(pq.size()==k&&nums1[i]+nums2[j]<pq.top().first+pq.top().second){
                    pq.pop();
                    pq.push({nums1[i],nums2[j]});
                }
                else if(pq.size()==k&&nums1[i]+nums2[j]>pq.top().first+pq.top().second){
                    break;
                }
            }
        }
        
        
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
