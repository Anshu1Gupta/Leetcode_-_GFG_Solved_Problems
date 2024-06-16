class Solution {
public:
    int findMin(vector<int>& arr) {
        
        
        int low=0;
        int high=arr.size()-1;
        int mini=1e9;
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(arr[low]<=arr[mid]){
                mini=min(arr[low],mini);
                low=mid+1;
            }
            else{
                mini=min(arr[mid],mini);
                high=mid-1;
            }
        }
        return mini;
    }
};