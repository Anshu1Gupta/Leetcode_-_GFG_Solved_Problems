class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>temp;
            for(int k=0;k<=i;k++){
                int x=0;int y=0;
               if(k==0){
                   y=ans[i-1][k];
               }
               else if(k==i){
                x=ans[i-1][k-1];
               }
                else {
                   x=ans[i-1][k-1];
                   y=ans[i-1][k];
                    
                }
                temp.push_back(x+y);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};