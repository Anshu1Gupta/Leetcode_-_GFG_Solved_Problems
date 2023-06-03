//intuition
// do BFS traversal along with time at which particular node got message
// so child of it will receive message at parent.time+ informTime[child]



class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map <int,vector<int>> mpp; //parent->children
        deque <pair<int,int>> dq; //vertex, time at which he will get message
        
        for(int i=0;i<n;i++)
            mpp[manager[i]].emplace_back(i);
        
        dq.push_back(make_pair(headID,informTime[headID]));
        int max_time= 0;
        
        while(!dq.empty())
        {
            auto temp = dq.front();
            dq.pop_front();
            max_time= max(max_time,temp.second);
            for(auto it:mpp[temp.first])
                dq.push_back(make_pair(it,temp.second+informTime[it])); 
        }
        return max_time;
    }
};