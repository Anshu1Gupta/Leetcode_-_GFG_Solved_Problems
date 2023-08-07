class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1;
        
        int ind=-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(matrix[mid][0]==target)return true;
            
            else if(matrix[mid][0]>target){
                high=mid-1;
            }
            else{
                ind=mid;
                low=mid+1;
            }
        }
        
        if(ind==-1)return false;
        
        low=0,high=matrix[0].size()-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(matrix[ind][mid]==target)return true;
            
            else if(matrix[ind][mid]>target)high=mid-1;
            else{
                low=mid+1;
            }
        }
        return false;
    }
};