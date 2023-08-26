class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int count=1;
        int maxi=0;
        int n=pairs.size();
        int l=0;
        int r=1;
        
        while(r<n){
            if(pairs[l][1]<pairs[r][0]){
                count++;
                l=r;
                r++;
            }
            else if(pairs[l][1]<=pairs[r][1]){
                r++;
            }
            else if(pairs[l][1]>pairs[r][1]){
                l=r;
                r++;
            }
            maxi=max(maxi,count);
        }
         maxi=max(maxi,count);
       return maxi; 
    }
};