class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
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
        if(arr.size()==0)return true;
        if(pq.empty())return false;
        // cout<<pq.size()<<endl;
        int count=0;
        while(!pq.empty()){
            count++;
            int ext=pq.top();pq.pop();
            for(auto it:adj[ext]){
                indegree[it]--;
                if(indegree[it]==0){
                    pq.push(it);
                }
            }
        }
        cout<<count;
      return count==numCourses;
        
        
    }
};