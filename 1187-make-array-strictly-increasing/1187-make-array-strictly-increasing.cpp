class Solution {
public:
    map<pair<int,int>,int>mp;
    int nways(int currIndex,vector<int>& arr1, vector<int>& arr2,int preValue){
        if(currIndex>=arr1.size())return 0;
        if(mp.find({currIndex,preValue})!=mp.end())return mp[{currIndex,preValue}];
        int res=1e9+1,res2=1e9+1;
        if(preValue<arr1[currIndex]){
            res=nways(currIndex+1,arr1,arr2,arr1[currIndex]);
        }
        int ind=upper_bound(arr2.begin(),arr2.end(),preValue)-arr2.begin();
        if(ind!=arr2.size()){
             res2=1+nways(currIndex+1,arr1,arr2,arr2[ind]);
        }
        
        
        return mp[{currIndex,preValue}]=min(res,res2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(arr2.begin(),arr2.end());
        
        int result=nways(0,arr1,arr2,-1);
        return result==1e9+1?-1:result;
    }
};