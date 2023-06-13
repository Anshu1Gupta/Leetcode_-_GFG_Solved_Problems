class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       map<vector<int>,int>row;
        for(auto it:grid){
            row[it]+=1;
           
        }
        for(int i=0;i<grid.size();i++){
            for(int j=i;j<grid[0].size();j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        
        int sum=0;
         for(auto it:grid){
           if(row.find(it)!=row.end()){
               sum+=row[it];
           }
        }
        return sum;
        
    }
};