class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        unordered_map<int,int>mpF;
        for(auto it:mp){
            if(mpF.find(it.second)!=mpF.end())return false;
            mpF[it.second]++;
        }
        return true;
    }
};