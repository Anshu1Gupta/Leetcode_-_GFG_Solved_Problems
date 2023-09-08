class Solution {
public:
    bool dfs(int source,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path){
        path[source]=1;
        visited[source]=1;
        for(auto v:adj[source]){
            if(visited[v]==0){
                if(dfs(v,adj,visited,path))return true;
            }
            else if(path[v])return true;
        }
        path[source]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V=graph.size();
        int edge=graph[0].size();
    
        
        vector<int>path(V,0),visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited,path);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(path[i]==0){
                ans.push_back(i);
            }
            else{
                // ans.push_back(i);
            }
        }
        return ans;
    }
};