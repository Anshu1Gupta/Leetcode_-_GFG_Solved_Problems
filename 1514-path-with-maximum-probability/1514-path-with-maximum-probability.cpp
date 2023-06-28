class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sucProb, int start, int end) {
     vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],sucProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],sucProb[i]});
        }
        
        vector<double>prob(n+1,-1);
        priority_queue<pair<double,int>>pq;
        if(start==end)return 0.000;
        prob[start]=1.0;
        pq.push({1.0,start});
        
        while(!pq.empty()){
            int node=pq.top().second;
            double pro=pq.top().first;
            pq.pop();
            for(auto adjNode: adj[node]){
                int v=adjNode.first;
                double proAdj=adjNode.second;
                
               if(proAdj*pro>prob[v]){
                  prob[v]=proAdj*pro;
                  pq.push({prob[v],v});
                   
              }
            }
        }
        if(prob[end]==-1)return 0.00;
        return prob[end];
    }
};