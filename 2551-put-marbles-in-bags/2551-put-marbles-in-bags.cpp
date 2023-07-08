class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>ans;
        for(int i=1;i<weights.size();i++){
            ans.push_back(weights[i]+weights[i-1]);
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        for(auto it:ans){
            cout<<it<<endl;
        }
        long long mini=0;
        for(int i=0;i<k-1;i++){
          mini+=ans[i];
        }
        long long maxi=0;
        for(int i=0;i<k-1;i++){
            maxi+=ans[n-i-1];
        }
        return maxi-mini;
    }
};