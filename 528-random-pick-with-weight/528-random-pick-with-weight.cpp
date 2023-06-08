class Solution {
public:
   vector<int>prefixSum;
    Solution(vector<int>& w) {
        prefixSum.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            prefixSum.push_back(prefixSum.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int random=rand()%prefixSum.back();
        int ind=upper_bound(prefixSum.begin(),prefixSum.end(),random)-prefixSum.begin();
        
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */