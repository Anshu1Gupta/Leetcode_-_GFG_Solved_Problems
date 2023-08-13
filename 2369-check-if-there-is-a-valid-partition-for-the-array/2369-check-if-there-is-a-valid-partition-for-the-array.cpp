class Solution {
public:
//     bool check(int start,int end,vector<int>&arr){
//         int len=end-start+1;
        
//         if(len==2&&arr[start]==arr[end])return true;
//         if(len==3&&arr[start]==arr[start+1]&&arr[start]==arr[end])return true;
//         if(len==3&&(arr[start]+1==arr[start+1]&&arr[start+1]+1==arr[end]))return true;
        
//         return false;
//     }
    bool ifvalid(int ind,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(ind>=arr.size())return true;
        
        
        if(dp[ind]!=-1)return dp[ind];
        
        bool one=false,two=false,three=false;
        
        if(ind+1<n&&(arr[ind]==arr[ind+1])){
            one=ifvalid(ind+2,arr,dp);
            if(one)return true;
        }
        if(ind+2<n&&(arr[ind]==arr[ind+1]&&arr[ind+1]==arr[ind+2])){
            two=ifvalid(ind+3,arr,dp);
            if(two)return true;
        }
        if(ind+2<n&&(arr[ind]==arr[ind+1]-1&&arr[ind+1]==arr[ind+2]-1)){
            three=ifvalid(ind+3,arr,dp);
            if(three)return true;
        }
        
        
        dp[ind]=one|two|three;
    
        return dp[ind];
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n,-1);
        return ifvalid(0,nums,dp);
    }
};