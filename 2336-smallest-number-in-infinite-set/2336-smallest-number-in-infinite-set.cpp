class SmallestInfiniteSet {
public:
    map<int,int>mp;
    priority_queue<int,vector<int>,greater<int>>pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.push(i);
            mp[i]++;
        }
        
    }
    
    int popSmallest() {
        if(pq.empty())return -1;
        
        else{
            int ele=pq.top();
            pq.pop();
            mp.erase(ele);
           return ele;
        }
    
    }
    
    void addBack(int num) {
        
        if(mp.find(num)==mp.end()){
            mp[num]++;
            pq.push(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */