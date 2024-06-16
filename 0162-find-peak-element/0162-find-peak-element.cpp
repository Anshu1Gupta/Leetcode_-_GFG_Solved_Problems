class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int low=1;
        int high=arr.size()-1;
        
        
        while(low<=high){
            int mid=(low+high)/2;
            
            
            if(arr[mid-1]>=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};