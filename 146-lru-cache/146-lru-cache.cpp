class LRUCache {
    list<pair<int,int>> dq; 
       unordered_map<int,list<pair<int, int>>::iterator>mp;
	int csize;
public:
    LRUCache(int capacity) {
        csize=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        int value=mp[key]->second;
        dq.erase(mp[key]);
        dq.push_front({key,value});
        mp[key]=dq.begin();
        return value;
    }
    
    void put(int key, int value) {
       
        if(mp.find(key)!=mp.end()){
            dq.erase(mp[key]);
            mp.erase(key);
        }
        if(dq.size()==csize){
            int kee=dq.back().first;
            dq.pop_back();
            mp.erase(kee);
        }
       
        dq.push_front({key,value});
        mp[key]=dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */