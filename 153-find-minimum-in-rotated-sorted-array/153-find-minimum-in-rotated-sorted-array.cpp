class Solution {
public:
    int findMin(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int ans=1e9;
        if(arr[i]<=arr[j])return arr[i];
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[i]<=arr[mid]){
                ans=min(ans,arr[i]);
                i=mid+1;
            }
            else{
                if(mid-1>=0&&arr[mid-1]>=arr[mid]){
                    return arr[mid];
                }
                else{
                    j=mid-1;
                }
            }
        }
        return ans;
    }
};