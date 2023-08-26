//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    void mapString(unordered_map<int,string>&mp){
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
    }
    void findComb(int ind,string &temp,vector<string>&ans,int arr[],int n,unordered_map<int,string>&mp){
        if(ind>=n){
          ans.push_back(temp);
          return;
        }
        
        string str=mp[arr[ind]];
        
        for(auto it:str){
            temp.push_back(it);
            findComb(ind+1,temp,ans,arr,n,mp);
            temp.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int,string>mp;
        mapString(mp);
        
        vector<string>ans; 
        string temp;
        findComb(0,temp,ans,a,N,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends