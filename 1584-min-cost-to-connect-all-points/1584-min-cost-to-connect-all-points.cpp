class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<vector<int>>adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int u=i;
                int v=j;
                int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                
                adj[u].push_back({v,distance});
                adj[v].push_back({u,distance});
            }
        }
        
        
        q.push({0,0});
        int sum=0;
        vector<int>visited(n+1,0);
        
        
        while(!q.empty()){
            int node=q.top().second;
            int dist=q.top().first;
            
            q.pop();
            if(visited[node]==1)continue;
            
            visited[node]=1;
            sum+=dist;
            for(auto v:adj[node]){
                 int ad=v[0];
                 int di=v[1];
                if(!visited[ad]){
                    q.push({di,ad});
                }
            }
        }
        
        return sum;
    }
    
};