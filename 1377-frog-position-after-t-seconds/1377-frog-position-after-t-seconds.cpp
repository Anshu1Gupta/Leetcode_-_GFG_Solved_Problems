class Solution {
public:
double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
   	 vector<int>adj[n+1];
       for(auto it:edges){
           int u=it[0];
           int v=it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       queue<int>q;
       vector<double>prob(n+1,0);
       vector<int>visited(n+1,0);
       q.push(1);
       visited[1]=1;
       prob[1]=1.0;
       while(!q.empty()&&t--){
          int size=q.size();
          while(size--){
            double extra=0;
            int node=q.front();q.pop();
            for(auto it:adj[node]){
               if(!visited[it])extra++;
            }
            for(auto v:adj[node]){
                if(!visited[v]){
                   visited[v]=1;
                    q.push(v);
                    prob[v]=prob[node]/extra;
                }
            }
             if(extra>0)
            prob[node]=0;
          }
       }


return prob[target];
          
 }
};
