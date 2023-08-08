class Solution {
public:
void findComb(int ind,int target,vector<int>&temp,vector<vector<int>>&ans,vector<int>&visited,int k){
    if(target==0){
        if(temp.size()==k){
        ans.push_back(temp);
       
        }
         return ;
    }
    if(target<0||ind>9)return;
    
    for(int i=ind;i<=9;i++){
        if(!visited[i]){
            visited[i]=1;
            temp.push_back(i);
            findComb(i+1,target-i,temp,ans,visited,k);
            temp.pop_back();
            visited[i]=0;
        }
    }
    
}
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>visited(10,0);
        findComb(1,n,temp,ans,visited,k);
        return ans;
    }
};