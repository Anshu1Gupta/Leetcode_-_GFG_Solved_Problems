class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                if(j==0)temp.push_back(ans[i-1][0]);
                else if(j==i)temp.push_back(ans[i-1][j-1]);
                
                else{
                    int left=ans[i-1][j];
                    int right=ans[i-1][j-1];
    
                    temp.push_back(left+right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};