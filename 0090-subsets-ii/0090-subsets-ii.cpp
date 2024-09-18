class Solution {
public:
void findSet(int ind,vector<int>&temp,vector<vector<int>>&ans,vector<int>&arr){
    if(ind>=arr.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(arr[ind]);
    findSet(ind+1,temp,ans,arr);
    temp.pop_back();
    while(ind+1<arr.size()&&arr[ind+1]==arr[ind])ind++;
    findSet(ind+1,temp,ans,arr);
}
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>temp;
    findSet(0,temp,ans,arr);
    return ans;
    }
};