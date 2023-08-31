class Solution {
public:
    vector<int>nextSmallerLeft(vector<int>&heights){
        stack<pair<int,int>>st;
        int n=heights.size();
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top().first>=heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({heights[i],i});
        }
        return ans;
    }
     vector<int>nextSmallerRight(vector<int>&heights){
        stack<pair<int,int>>st;
        int n=heights.size();
        vector<int>ans(n);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first>=heights[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({heights[i],i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=nextSmallerLeft(heights);
        vector<int>right=nextSmallerRight(heights);
        
        int maxi=0;
        for(int i=0;i<n;i++){
            int area=(right[i]-left[i]-1)*heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
};