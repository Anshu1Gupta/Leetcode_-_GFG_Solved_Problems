//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
      vector<pair<int,int>>p;
      for(int i=0;i<nums.size();i++){
          p.push_back({nums[i],i});
      }
      sort(p.begin(),p.end());
      
      int swaps=0;
      for(int i=0;i<nums.size();i++){
          if(p[i].second==i)continue;
          
          swap(p[i],p[p[i].second]);
          i--;swaps++;
      }
      return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends