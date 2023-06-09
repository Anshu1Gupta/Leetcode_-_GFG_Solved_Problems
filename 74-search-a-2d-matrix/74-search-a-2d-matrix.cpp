class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int row=-1;
        int j=matrix.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]<target){
                row=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        if(row==-1)return false;
        
    i=0;
    j=matrix[0].size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return false;
    }
};