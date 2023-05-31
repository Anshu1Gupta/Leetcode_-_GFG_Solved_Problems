class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
          vector<int>indegree(numCourses,0);
        for(auto it:arr){
            indegree[it[0]]++;
        }
        vector<int>adj[numCourses];
        for(auto it:arr){
            adj[it[1]].push_back(it[0]);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                pq.push(i);
            }
        }
        vector<int>ans;
        
        int count=0;
        while(!pq.empty()){
            count++;
            int ext=pq.top();pq.pop();
            ans.push_back(ext);
            for(auto it:adj[ext]){
                indegree[it]--;
                if(indegree[it]==0){
                    pq.push(it);
                }
            }
        }
        if(count==numCourses){
            return ans;
        }
        return {};
       
    }
};