class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())return "";
        int n=s.size();
        vector<int>mp(128,0);
        for(auto ch:t){
            mp[ch]++;
        }
        int reqSize=t.length();
        int minWind=INT_MAX;
        int start=0;
        int i=0;
        int j=0;
        while(j<n){
            if(mp[s[j]]>0){
                reqSize--;
            }
            mp[s[j]]--;
            
            while(reqSize==0){
                int sizeFind=j-i+1;
                if(sizeFind<minWind){
                    minWind=sizeFind;
                    start=i;
                }
                
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    reqSize++;
                }
                i++;
                
            }j++;
        }
        return minWind==INT_MAX?  "": s.substr(start,minWind);
        
    }
};