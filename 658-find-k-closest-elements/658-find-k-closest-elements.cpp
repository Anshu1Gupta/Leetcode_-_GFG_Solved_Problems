class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(int i=0;i<arr.size();i++){
           int dist=abs(x-arr[i]);
            pq.push({dist,arr[i]});
            if(pq.size()>k){
                auto x=pq.top();pq.pop();
                auto y=pq.top();pq.pop();
                if(x.first<y.first){
                    pq.push(x);
                }
                else if(x.first>y.first){
                    pq.push(y);
                }
                else{
                if(x.second<y.second){
                    pq.push(x);
                }else pq.push(y);
                }
            }
           
            
        }
        vector<int>ans(k);
        for(int i=k-1;i>=0;i--){
            ans[i]=pq.top().second;pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};