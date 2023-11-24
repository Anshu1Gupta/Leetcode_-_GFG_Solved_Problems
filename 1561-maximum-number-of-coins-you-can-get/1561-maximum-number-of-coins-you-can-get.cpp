class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.rbegin(), piles.rend());
        int ans=0;
        int k=n/3*2;
        #pragma unroll
        for(int i=1; i<k; i+=2)
            ans+=piles[i];
        return ans;
    }
};