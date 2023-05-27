class TimeMap {
public:
    map<pair<string , int> , string > mp;

    TimeMap() {}

    void set(string key, string val, int tt) { mp[{key , tt}] = val; }

    string get(string key, int tt) {
        auto it = mp.lower_bound({key,tt});
        if(it != mp.end()) if((*it).first.first == key && (*it).first.second <= tt ) return (*it).second; it--;
        if((*it).first.first == key && (*it).first.second <= tt ) return (*it).second; return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */