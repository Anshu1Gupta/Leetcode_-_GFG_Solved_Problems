class Solution {
public:
    void possibleCombination(int ind,int n,vector<int>&visited,vector<vector<int>>&ans,vector<int>&temp,int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<=n;i++){
            if(!visited[i]){
               visited[i]=1;
               temp.push_back(i);
               possibleCombination(i+1,n,visited,ans,temp,k);
               temp.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(n+1,0);
        
        possibleCombination(1,n,visited,ans,temp,k);
        
        return ans;
    }
};