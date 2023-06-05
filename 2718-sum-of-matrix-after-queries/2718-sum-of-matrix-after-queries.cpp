class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int>visitedr(n,0),visitedc(n,0);
        long long ans=0;
        int r=0,c=0;
        for(int i=queries.size()-1;i>=0;i--){
            int type=queries[i][0];
            int ind=queries[i][1];
            int value=queries[i][2];
            if(type==0){
                if(visitedr[ind]==0){
                    ans+=1LL*value*(n-c);
                    visitedr[ind]=1;
                    r++;
                }
            }
            if(type==1){
                if(visitedc[ind]==0){
                    ans+=1LL*value*(n-r);
                    visitedc[ind]=1;
                    c++;
                }
            }
        }
        return ans;
    }
};