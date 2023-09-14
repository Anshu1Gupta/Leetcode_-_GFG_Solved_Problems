class Solution {
public:
    vector<string>ans;
    bool dfs(string source,unordered_map<string,vector<string>>&adj,vector<string>&path,int tic){
        path.push_back(source);
        if(path.size()==tic+1){
            ans=path;
            return true;
        }
        vector<string>&neighbours=adj[source];
        for(int i=0;i<neighbours.size();i++){
            string des=neighbours[i];
            neighbours.erase(neighbours.begin()+i);
            if(dfs(des,adj,path,tic))return true;
            neighbours.insert(neighbours.begin()+i,des);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(auto it:tickets){
            string from=it[0];
            string to=it[1];
            adj[from].push_back(to);
        }
        for(auto &it:adj){
            sort(it.second.begin(),it.second.end());
        }
        string source="JFK";
        vector<string>path;
        int tic=tickets.size();
        if(dfs(source,adj,path,tic))return ans;
        return {};
    }
};