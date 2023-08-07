class Solution {
public:
    bool search(vector<int>&arr,int key){
        int low=0,high=arr.size()-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==key)return true;
            else if(arr[mid]<key)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++){
            if(search(matrix[i],target))return true;
        }
        return false;
        
    }
};