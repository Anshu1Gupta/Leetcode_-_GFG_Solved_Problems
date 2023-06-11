class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int l=0;
        int r=1;
        int n=intervals.size();
        int count=0;
        while(r<n){
            if(intervals[l][1]<=intervals[r][0]){
                l=r;
                r++;
            }
            else if(intervals[l][1]<=intervals[r][1]){
                count++;
                r++;
            }
            else if(intervals[l][1]>intervals[r][1]){
                count++;
                l=r;
                r++;
            }
        }
        return count;
    }
};