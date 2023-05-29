class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size(),0);
        stack<pair<int,int>>st;
        for(int i=0;i<temp.size();i++){
            if(st.empty()||st.top().first>=temp[i]){
                st.push({temp[i],i});
            }
            else{
                while(!st.empty()&&st.top().first<temp[i]){
                    auto node=st.top();st.pop();
                    ans[node.second]=(i-node.second);
                }
                st.push({temp[i],i});
            }
        }
        return ans;
    }
};