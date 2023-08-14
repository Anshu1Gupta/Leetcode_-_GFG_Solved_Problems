class Solution {
public:
    void dfs(int source,vector<vector<int>>& adj,vector<int>&visited){
        visited[source]=1;
        
        for(auto v:adj[source]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        dfs(0,rooms,visited);
        
        for(int i=0;i<n;i++){
            if(visited[i]==0)return false;
        }
        return true;
    }
};