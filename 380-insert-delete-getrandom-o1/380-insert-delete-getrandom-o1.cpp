class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> num;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
            m[val]=num.size();
            num.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end())
        {
            // replace the element val in num by last element of num and delete last element of num
            int ind=m[val];
            num[ind]=num[num.size()-1];
            m[num[num.size()-1]]=ind;
            num.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int p=rand()%num.size();
        return num[p];
    }
};