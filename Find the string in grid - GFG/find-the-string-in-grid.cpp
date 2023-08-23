//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	  bool findAll(int i,int j,string &word,vector<vector<char>>&grid){
    int n=grid.size(),m=grid[0].size();
    // int k=0;
   
   
   string str="";
   
   //horizontal right
   for(int k=j;k<m;k++){
       str+=grid[i][k];
       if(str==word)return true;
   }
   
   str="";
   
   
   //vertical downward
    for(int k=i;k<n;k++){
       str+=grid[k][j];
        if(str==word)return true;
   }
  
   str="";
   //vertically upward
   for(int k=i;k>=0;k--){
       str+=grid[k][j];
       if(str==word)return true;
   }
   
   str="";
   //horizontal left
   for(int k=j;k>=0;k--){
       str+=grid[i][k];
       if(str==word)return true;
   }
   
   str="";
   //diagonally downright
    int x=i;
    int y=j;
    while(x<n&&y<m){
       str+=grid[x][y];
       x++;y++;
       if(str==word)return true;
    }
    
    x=i;
    y=j;
    str="";
    //digonally downleft
    while(x<n&&y>=0){
       str+=grid[x][y];
       x++;y--;
       if(str==word)return true;
    }
    
    x=i;
    y=j;
    str="";
    //diagonally upleft
     while(x>=0&&y>=0){
       str+=grid[x][y];
       x--;y--;
       if(str==word)return true;
    }
    
    x=i;
    y=j;
   str="";
    //diagonally upright
     while(x>=0&&y<m){
       str+=grid[x][y];
       x--;y++;
       if(str==word)return true;
    }
   
   return false;
 }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>ans;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                if(findAll(i,j,word,grid)){
	                    ans.push_back({i,j});
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends