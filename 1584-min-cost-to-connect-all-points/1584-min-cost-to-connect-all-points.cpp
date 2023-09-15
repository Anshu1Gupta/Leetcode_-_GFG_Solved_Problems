class DisjointSet{
    public:
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1),size.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }
    }
    
    int findUParent(int node){
        if(node==parent[node])return parent[node];
        return parent[node]=findUParent(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ult_u=findUParent(u);
        int ult_v=findUParent(v);
        
        if(ult_u==ult_v)return ;
        
        if(size[ult_u]>size[ult_v]){
            size[ult_u]+=size[ult_v];
            parent[ult_v]=ult_u;
        }
        else{
            size[ult_v]+=size[ult_u];
            parent[ult_u]=ult_v;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>edges;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
            }
        }
        DisjointSet ds(n);
        int sum=0;
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int u=it[1];
            int v=it[2];
            int dist=it[0];
            
            if(ds.findUParent(u)!=ds.findUParent(v)){
                ds.unionBySize(u,v);
                sum+=dist;
            }
        }
        return sum;
    }
};