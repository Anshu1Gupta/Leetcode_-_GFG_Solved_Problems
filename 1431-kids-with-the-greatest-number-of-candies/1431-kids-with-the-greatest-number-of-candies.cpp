class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=*max_element(candies.begin(),candies.end());
        int n=candies.size();
        vector<bool>ans;
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};