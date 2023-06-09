class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int price=it[2];
            adj[u].push_back({v,price});
        }
        vector<int>visited(n+1,0);
        queue<pair<pair<int,int>,int>>q;
        q.push({{src,0},0});
        vector<int>distance(n,1e9);
       
        while(!q.empty()){
            int u=q.front().first.first;
            int stops=q.front().first.second;
            int cost=q.front().second;
            q.pop();
           
            for(auto it: adj[u]){
                int v=it.first;
                int price=it.second;
                cout<<v<<' '<<stops<<" "<<price+cost<<endl;
                
                if(stops>k)continue;
               else{
                 if(price+cost<distance[v]&&stops<=k){
                 distance[v]=price+cost;
                 q.push({{v,stops+1},distance[v]});
             }
               }
            }
        }
        return distance[dst]==1e9?-1:distance[dst];
    }
};