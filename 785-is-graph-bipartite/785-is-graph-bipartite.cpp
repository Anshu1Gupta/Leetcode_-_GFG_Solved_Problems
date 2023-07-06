class Solution {
public:
    bool bfs(int u,vector<vector<int>>&adj,vector<int>&color){
        queue<pair<int ,int >>q;
        q.push({u,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                 if(color[it]==-1){
                     color[it]=!col;
                     q.push({it,color[it]});
                 }
                else if(color[it]==col)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
           if(color[i]==-1){
                if(bfs(i,graph,color)==false)return false;
           }
        }
        
        return true;
    }
};