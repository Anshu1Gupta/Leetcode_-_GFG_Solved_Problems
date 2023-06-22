class Solution {
public:
void findSet(int ind,vector<int>&temp,set<vector<int>>&ans,vector<int>&arr){
    if(ind>=arr.size()){
        ans.insert(temp);
        return;
    }

    temp.push_back(arr[ind]);
    findSet(ind+1,temp,ans,arr);
    temp.pop_back();
    findSet(ind+1,temp,ans,arr);
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    set<vector<int>>ans;
    vector<int>temp;
    findSet(0,temp,ans,arr);
    vector<vector<int>>res;
    set<vector<int>>ans1;
    for(auto it:ans){
        sort(it.begin(),it.end());
        ans1.insert(it);
    }
        for(auto it:ans1){
            res.push_back(it);
        }
    return res;
    }
};