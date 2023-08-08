class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        vector<pair<int,int>>poi;
        int first=points[0][0];
        int second=points[0][1];
        
        
        int n=points.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(second<points[i][0]){
                first=points[i][0];
                second=points[i][1];
                count++;
            }
            else{
                first=max(first,points[i][0]);
                second=min(second,points[i][1]);
            }
        }
        return count+1;
    }
};