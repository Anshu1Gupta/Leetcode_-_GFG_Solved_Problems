class Solution {
public:
     vector<int> nextRight(vector<int>&height){
        stack<int>st;
        vector<int>ans;
        int n=height.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(n);
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> nextLeft(vector<int>&height){
        stack<int>st;
        vector<int>ans;
        int n=height.size();
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]>=height[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        
        vector<int>com=nextRight(heights);
        vector<int>leftcom=nextLeft(heights);
        for(int i=0;i<com.size();i++){
            int val=com[i]-leftcom[i]-1;
            val=heights[i]*val;
            
            maxi=max(maxi,val);
        }
        return maxi;
    }
};