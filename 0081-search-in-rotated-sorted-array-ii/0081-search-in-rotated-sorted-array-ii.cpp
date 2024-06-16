class Solution {
public:
    bool search(vector<int>& arr, int target) {
        
        int low=0;
        int high=arr.size()-1;
        
        while(low<=high){
            
            while(low<=high && arr[low]==arr[high]){
                if(arr[low]==target)return true;
               low++;
            }
            if(low>high)return false;
            int mid=(low+high)/2;
            
            if(arr[low]<=arr[mid]){//it means left half is sorted.
                
                if(target==arr[low]|| target==arr[mid])return true;
                else if(target>arr[low] && target<arr[mid])high=mid-1;
                else{
                    low=mid+1;
                }
            }
            else{   //means right half is sorted 
                if(target==arr[mid]|| target==arr[high])return true;
                else if(target>arr[mid] && target<arr[high])low=mid+1;
                else{
                   high=mid-1;
                }
            }
                
        }
        return false;
        
    }
};


