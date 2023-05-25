class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int k=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            
            mp[s[i]]++;
            while(mp[s[i]]>=2){
                mp[s[k]]--;
                if(mp[s[k]]==0)mp.erase(s[k]);
                k++;
            }
            int len=mp.size();
            ans=max(ans,len);
            
        }
        return ans;
    }
};