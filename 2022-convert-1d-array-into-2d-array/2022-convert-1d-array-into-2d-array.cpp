class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size=original.size();
        int part=size/m;
        int k=0;
        int pp=min(m,n);
        int kk=max(m,n);
        if(m*n !=size)return {};
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            vector<int>ans;
            for(int j=0;j<n;j++){
                ans.push_back(original[k++]);
            }
            res.push_back(ans);
        }
        return res;
    }
};