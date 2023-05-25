class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        for(auto inter:intervals){
               if(inter[1]<newInterval[0]){
                   ans.push_back(inter);
               }
            else if(inter[0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval=inter;
            }
            else{
                newInterval[0]=min(newInterval[0],inter[0]);
                newInterval[1]=max(newInterval[1],inter[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
        
        
    }
};