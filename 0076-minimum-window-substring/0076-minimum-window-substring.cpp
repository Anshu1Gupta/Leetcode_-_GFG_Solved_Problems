class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())return "";
        int n=s.length();
        
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int len=t.length();
        int ans=1e9;
        int start=0;
        int end=0;
        int ind=0;
        while(end<n){
            if(mp[s[end]]>0){
                len--;
            }
            mp[s[end]]--;
            
            while(len==0){
                int length=end-start+1;
                if(length<ans){
                    ans=length;
                    ind=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0){
                    len++;
                }
                start++;
            }
            end++;
        }
        
        
        if(ans==1e9)return "";
        cout<<ans<<endl;
        return s.substr(ind,ans);
    }
};