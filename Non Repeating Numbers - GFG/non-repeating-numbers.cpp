//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
         int xorval = 0;
        for (int num : nums) {
            xorval ^= num;
        }
        int bitmask = xorval & (-xorval);
        
        int num1 = 0;
        for (int num : nums) {
            if ((num & bitmask) != 0) {
                num1 ^= num;
            }
        }
     int num2=num1^xorval;
     if(num1>num2){
         return {num2,num1};
     }
     else return {num1,num2};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends