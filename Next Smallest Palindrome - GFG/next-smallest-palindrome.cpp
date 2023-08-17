//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
    inline bool isPalin(int num[], int n){
        int i=0,j=n-1;
        while(i<=j) if(num[i++] != num[j--]) return false;
        return true;
    };
    vector<int> solve(int num[], int n) {
        vector<int> ans(num,num+n);
        int i=n/2;
	    if(!(n&1)) i--;
        int carry = ans[i]==9;
        ans[i] = (ans[i]+1)%10;
        ans[n-1-i] = ans[i--];
        
        while(i>=0) {
            ans[i] = ans[i] + carry;
            if(ans[i] == 10) {
                carry = 1;
                ans[i] = 0;
            }
            else carry = 0;
            ans[n-1-i] = ans[i--];
        }
        
        if(carry) {
            ans[n-1]=1;
            ans.insert(ans.begin(),1);
            
        }
        return ans;
    }
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    
	    
	    if(isPalin(num,n)) {
	        return solve(num,n);
	    }
	    else {
    	    int i=0 , j=n-1;
    	    bool cond = false;
    	    while(i<=j) {
    	        if(num[i] < num[j]) 
    	            cond = true;
    	        else if(num[i] > num[j]) cond = false;
    	        
    	        num[j--] = num[i++];
    	    }
	        if(cond) return solve(num,n);
	    }
	    
	    return vector<int>(num, num+n);
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends