class Solution {
public:
    
    vector<int> nextRight(vector<int>&height){
        stack<int>st;
        vector<int>ans;
        int n=height.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(height[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> nextLeft(vector<int>&height){
        stack<int>st;
        vector<int>ans;
        int n=height.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(height[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        
          int x=height.size();

        vector<int>left(x,0);
        vector<int>right(x,0);
        left[0]=height[0];
        right[x-1]=height[x-1];
        for(int i=1;i<x;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=x-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<x;i++){
            int ans=min(left[i],right[i])-height[i];
            sum+=ans;
        }
        return sum;
    }
};