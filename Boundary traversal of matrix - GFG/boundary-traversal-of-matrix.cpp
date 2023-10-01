//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int>ans;
        
        int up=0,down=n-1,left=0,right=m-1;
        
        for(int i=left;i<=right;i++)ans.push_back(matrix[up][i]);
        up++;
        
        for(int i=up;i<=down;i++)ans.push_back(matrix[i][right]);
        right--;
        
        if(up<=down){
            for(int i=right;i>=left;i--)ans.push_back(matrix[down][i]);
            down--;
        
        }
        
        if(left<=right){
            for(int i=down;i>=up;i--)ans.push_back(matrix[i][left]);
            left++;
        }
      
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends