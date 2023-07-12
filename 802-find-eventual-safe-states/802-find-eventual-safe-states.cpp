class Solution {
public:
bool dfs(int source,vector<int>&visited,vector<vector<int>>&graph,vector<int>&mark){
       mark[source]=1;
       visited[source]=1;
       
       for(auto it:graph[source]){
           if(visited[it]==-1){
               if(dfs(it,visited,graph,mark)){
                   return true;
               }
           }
           else if(mark[it]){
               return true;
           }

       }
       
       mark[source]=0;
       return false;
       
   } 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        vector<int>pathVisited(n,-1);
        
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                dfs(i,visited,graph,pathVisited);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(pathVisited[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};