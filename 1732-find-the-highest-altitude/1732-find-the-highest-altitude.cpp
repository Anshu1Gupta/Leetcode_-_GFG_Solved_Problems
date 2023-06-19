class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=-1e9;
        int n=gain.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+gain[i];
            maxi=max(maxi,sum);
        }
        return maxi<=0?0:maxi;
    }
};