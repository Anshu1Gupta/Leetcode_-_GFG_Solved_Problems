class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      int row=matrix[0].size();
      int col=matrix.size();
        
      vector<vector<int>>arr(row,vector<int>(col));
    
        for(int j=0;j<matrix[0].size();j++){
            for(int i=0;i<matrix.size();i++){
                arr[j][i]=matrix[i][j];
            }
        }
        return arr;
        
    }
};
