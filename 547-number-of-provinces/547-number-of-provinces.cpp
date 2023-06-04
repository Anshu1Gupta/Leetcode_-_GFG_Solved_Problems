class Solution {
public:
    void bfs(int source,vector<int>&visited,vector<int>adj[]){
        queue<int>q;
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto v:adj[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int size=n+1;
        vector<int>adj[size];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count=0;
        vector<int>visited(size,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                bfs(i,visited,adj);
                count++;
            }
        }
        return count;
        
    }
};