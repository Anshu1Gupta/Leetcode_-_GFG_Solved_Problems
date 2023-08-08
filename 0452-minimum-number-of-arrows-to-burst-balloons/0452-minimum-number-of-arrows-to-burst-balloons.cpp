class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        vector<pair<int,int>>poi;
        poi.push_back({points[0][0],points[0][1]});
        int n=points.size();
        
        for(int i=1;i<n;i++){
            if(poi.back().second<points[i][0]){
                poi.push_back({points[i][0],points[i][1]});
            }
            else{
                poi.back().first=max(poi.back().first,points[i][0]);
                poi.back().second=min(poi.back().second,points[i][1]);
            }
        }
        return poi.size();
    }
};