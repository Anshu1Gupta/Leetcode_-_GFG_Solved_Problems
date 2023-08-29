//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       
       for(int col=0;col<n;col++){
           
           int count=0;
           for(int row=0;row<n;row++){
            //   if(row!=col)
               if(M[row][col]==1)count++;
           }
           
           if(count==n-1){
               int flag=0;
               for(int k=0;k<n;k++){
                   if(M[col][k]!=0){
                       flag=1;
                       break;
                   }
               }
               if(flag==0)return col;
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends