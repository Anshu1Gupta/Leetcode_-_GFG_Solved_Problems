class Solution {
public:
    vector<int> countBits(int n) {
        
        
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int count=0;
            for(int k=0;k<32;k++){
                if(i&(1<<k))count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};