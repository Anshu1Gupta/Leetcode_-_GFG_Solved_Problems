class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>ans=heights;
        sort(heights.begin(),heights.end());
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=ans[i])count++;
        }
        return count;
        
    }
};