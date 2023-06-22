class Solution {
public:
void subset(int ind,vector<int>&temp,vector<vector<int>>&ans,int sum,vector<int>&arr,int curr){
   
   if(sum==curr){
       ans.push_back(temp);
       return;
   }
   if(ind>=arr.size())return;

  if(curr<sum){
   temp.push_back(arr[ind]);
   subset(ind,temp,ans,sum,arr,curr+arr[ind]);
   temp.pop_back();
  }
   while(ind+1<arr.size()&&arr[ind]==arr[ind+1])ind++;
   subset(ind+1,temp,ans,sum,arr,curr);
}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        int n=arr.size();
        vector<int>temp;
        sort(arr.begin(),arr.end());
        subset(0,temp,ans,target,arr,0);
        return ans;
    }
};