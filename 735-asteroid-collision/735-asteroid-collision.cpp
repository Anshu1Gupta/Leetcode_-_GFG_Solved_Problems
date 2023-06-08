class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()||st.top()>=0&&asteroids[i]>=0||st.top()<0&&asteroids[i]<0){
                st.push(asteroids[i]);
            }
            else{
                if(asteroids[i]<0){
                    while(!st.empty()&&st.top()>=0&&(abs(st.top())<abs(asteroids[i]))){
                        st.pop();
                    }
                    if(!st.empty()&&st.top()>=0&&abs(st.top())==abs(asteroids[i])){
                        st.pop();
                    }
                    else if(st.empty()||st.top()<0){
                        st.push(asteroids[i]);
                    }
                    
                }
                if(asteroids[i]>=0){
                    st.push(asteroids[i]);
                }
            }
            
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};