class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>sm,tm;
        
        for(auto it:s)sm[it]++;
        for(auto it:t)tm[it]++;
        
        int count=0;
        
        for(auto it:sm){
            if(tm.find(it.first)!=tm.end()){
                count+=min(tm[it.first],sm[it.first]);
            }
        }
        return s.length()-count;
    }
};