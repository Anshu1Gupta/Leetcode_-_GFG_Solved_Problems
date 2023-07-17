class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string>st;
        int maxLen=0;
        for(auto it:forbidden){
            st.insert(it);
            int len=it.length();
            maxLen=max(maxLen,len);
        }
        int ans=0,start=0,end=0,n=word.length();
        while(end<n){
            
            int i=end;
            string temp;
            for(;i>=start&&i>(end-maxLen);i--){
                temp=word[i]+temp;
                if(st.find(temp)!=st.end()){
                    start=i+1;
                    break;
                }
            }
            
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};