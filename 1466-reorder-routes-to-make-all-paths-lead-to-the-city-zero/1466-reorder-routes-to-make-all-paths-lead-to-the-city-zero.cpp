class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        set<pair<int,int>>set;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            set.insert({u,v});
        }
        
        queue<int>q;
        q.push(0);
        
        vector<int>visited(n);
        visited[0]=1;
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            
            for(auto v:adj[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=1;
                    if(set.find({node,v})!=set.end())count++;
                }
            }
            
        }
        return count;
        
    }
};