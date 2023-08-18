class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        map<pair<int,int>,int>mp;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            mp[{u,v}]++;
            mp[{v,u}]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int n_roads=0;
                if(mp.find({i,j})==mp.end()){
                    n_roads=adj[i].size()+adj[j].size();
                }
                else{
                    n_roads=adj[i].size()+adj[j].size()-1;
                }
                sum=max(sum,n_roads);
            }
        }
        return sum;
       
    }
};

// 0->1
    


