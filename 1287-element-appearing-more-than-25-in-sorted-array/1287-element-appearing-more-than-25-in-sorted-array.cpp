class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n =arr.size();
        double perc;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int num=0;
        int val=-1;
        for(auto it:mp){
            if(num<it.second){
                num=it.second;
                val=it.first;
            }
        }
        return val;
        
        
        
    }
};