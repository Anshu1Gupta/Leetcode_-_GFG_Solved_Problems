//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void findPerm(int ind,string &str,string &temp,vector<string>&ans){
	    if(temp.size()==str.size()){
	        ans.push_back(temp);
	        return ;
	    }
	    
	    if(str[ind]!='?'){
	        temp.push_back(str[ind]);
	        findPerm(ind+1,str,temp,ans);
	        temp.pop_back();
	    }
	    else{
	        temp.push_back('0');
	        findPerm(ind+1,str,temp,ans);
	        temp.pop_back();
	        temp.push_back('1');
	        findPerm(ind+1,str,temp,ans);
	        temp.pop_back();
	    }
	}
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    vector<string>ans;
		    string temp;
		    findPerm(0,s,temp,ans);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends