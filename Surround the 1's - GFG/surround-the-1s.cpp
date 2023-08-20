//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
    int Count(vector<vector<int> >& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       int count=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
              if(matrix[i][j]==1){
                  int zeros=0;
                   for(auto it:dir){
                   int nx=i+it.first;
                   int ny=j+it.second;
                   if(nx>=0&&nx<n&&ny>=0&&ny<m&&matrix[nx][ny]==0){
                       zeros++;
                   }
               }
               if(zeros%2==0&&zeros!=0)count++;
              }
               
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends