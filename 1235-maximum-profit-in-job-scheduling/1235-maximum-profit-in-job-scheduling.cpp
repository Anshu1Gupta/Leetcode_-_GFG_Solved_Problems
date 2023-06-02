class Solution {
public:
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int n=array.size();
        int r = n-1;
        
        int result = n+1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(array[mid][0] >= currentJobEnd) { //we can take this task
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
    int maximum(vector<vector<int>>&job,int n,int ind,vector<int>&dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int nextInd=getNextIndex(job,ind+1,job[ind][1]);
        int take=job[ind][2]+maximum(job,n,nextInd,dp);
        int ntake=0+maximum(job,n,ind+1,dp);
        return dp[ind]=max(ntake,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>job(n,vector<int>(4,0));
        for(int i=0;i<profit.size();i++){
            job[i][0]=startTime[i];
            job[i][1]=endTime[i];
            job[i][2]=profit[i];
        }
        sort(job.begin(),job.end());
        
        vector<int>dp(n+1,-1);
        return maximum(job,n,0,dp);
    }
};