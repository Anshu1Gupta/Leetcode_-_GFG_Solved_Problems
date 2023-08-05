//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void findPerm(int ind,string &str,string &temp,vector<string>&ans,vector<int>&visited){
        
        if(temp.size()==str.size()){
            ans.push_back(temp);
            return;
        }
       
       for(int i=0;i<str.size();i++){
           if(visited[i]==0){
               visited[i]=1;
               temp+=str[i];
               findPerm(i+1,str,temp,ans,visited);
               temp.pop_back();
               visited[i]=0;
           }
       }
       
    }
    vector<string> permutation(string S)
    {
        string str;
        // sort(S.begin(),S.end());
        vector<string>ans;
        vector<int>visited(S.length(),0);
        findPerm(0,S,str,ans,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends