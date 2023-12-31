class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int length=-1;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
            
            else{
                length=max(length,i-mp[s[i]]-1);
            }
        }
        return length;
    }
};