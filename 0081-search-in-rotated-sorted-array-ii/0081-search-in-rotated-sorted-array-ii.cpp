class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        
        while(low<=high){
            
            while(low<=high&&arr[low]==arr[high]){
                if(arr[low]==target)return true;
                low++;
            }
            if(low>high)break;
            int mid=(low+high)/2;
            
            if(arr[mid]==target)return true;
            
            if(arr[low]<=arr[mid]){
                if(target==arr[low]||target==arr[mid])return true;
                
                else if(target>arr[low]&&target<arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target==arr[mid]||target==arr[high])return true;
                
                else if(target>arr[mid]&&target<arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        
        return false;
    }
};