class RecentCounter {
public:
    vector<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);
        int count=0;
        int upto=t-3000;
        for(int i=q.size()-1;i>=0;i--){
            if(q[i]>=upto)count++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */