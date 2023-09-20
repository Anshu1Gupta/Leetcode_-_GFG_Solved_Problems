class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            // auto vect=ans.back();
            // int u=vect[0];
            // int v=vect[1];
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                // u=min(u,intervals[i][0]);
                // v=max(v,intervals[i][1]);
                // ans.pop_back();
                // ans.push_back({u,v});
            }
            else{
              ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};