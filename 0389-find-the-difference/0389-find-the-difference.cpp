class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        
        for(auto it:t){
            mp[it]--;
            if(mp[it]<0)return it;
        }
        return ' ';
    }
};