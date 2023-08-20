class Solution {
public:
    double dfs(string source, string dest, unordered_map<string,vector<pair<string,double>>>&adj,unordered_set<string>&visited,double ans){
        visited.insert(source);
        if(source==dest&&adj.find(source)!=adj.end())return ans;
        
        
        double res =-1;
        for(auto it:adj[source]){
            string to=it.first;
            if(visited.find(to)==visited.end()){
                res=max(res,dfs(to,dest,adj,visited,ans*it.second));
            }
            
        }
        return res;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       unordered_map<string,vector<pair<string,double>>>mp;
    
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            
            double val=values[i];
            mp[u].push_back({v,val});
            mp[v].push_back({u,1/val});
        }
        vector<double>result;
        
        for(auto it:queries){
            string u=it[0];
            string v=it[1];
            unordered_set<string>visited;
            double ans=1.0;
            
            if(mp.find(u)==mp.end()||mp.find(v)==mp.end()){
                result.push_back(-1.000000);
            }
            else
            result.push_back(dfs(u,v,mp,visited,ans));
            
        }
        return result;
    }
};