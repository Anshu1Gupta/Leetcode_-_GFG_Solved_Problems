class Solution {
public:
    int maxEvents(int ind, vector<pair<pair<int,int>,int>>&vect,int k,vector<vector<int>>&dp){
        if(ind>=vect.size()||k<=0)return 0;
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        int i;
        for(i=ind+1;i<vect.size();i++){
            if(vect[ind].first.second<vect[i].first.first)break;
        }
        
        return dp[ind][k]= max(maxEvents(ind+1,vect,k,dp),vect[ind].second+maxEvents(i,vect,k-1,dp));
        
        
        
        // int take=0;
        // if(prev==-1||vect[prev].first.second<vect[ind].first.first){
        //     take=vect[ind].second+maxEvents(ind+1,ind,vect,k-1,dp);
        // }
        // int ntake=0+maxEvents(ind+1,prev,vect,k,dp);
        // return dp[ind][k]=max(take,ntake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<pair<pair<int,int>,int>>vect;
        for(auto it:events){
            vect.push_back({{it[0],it[1]},it[2]});
        }
        sort(vect.begin(),vect.end());
        int n=vect.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return maxEvents(0,vect,k,dp);
    }
};