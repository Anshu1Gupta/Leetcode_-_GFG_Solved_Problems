class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<char>mp1(26,0),mp2(26,0);
        set<char>s1,s2;
        if(word1.length()!=word2.length())return false;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]-'a']++;
            mp2[word2[i]-'a']++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }
        
        if(s1!=s2)return false;
       
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i])return false;
        }
        return true;
        
    }
};