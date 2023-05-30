class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
	  int maxi=arr[0];
	  int mini=arr[0];
	   int ans=arr[0];
	   for(int i=1;i<n;i++)
	   {
	       if(arr[i]<0){
	           swap(maxi,mini);
	       }
	       maxi=max(maxi*arr[i],arr[i]);
	       mini=min(mini*arr[i],arr[i]);
	       ans=max(ans,maxi);
	    }
	    return ans;
	}
};
