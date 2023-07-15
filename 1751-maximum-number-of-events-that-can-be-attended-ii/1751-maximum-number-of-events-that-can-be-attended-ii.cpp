class Solution {
public:
    int findSearch(int low, vector<pair<pair<int,int>,int>>&vect,int k){
        int high=vect.size()-1;
        int ind=vect.size();
        while(low<=high){
            int mid=(low+high)/2;
            
            if(vect[mid].first.first>k){
                ind=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
       return ind;
    }
    int maxEvents(int ind, vector<pair<pair<int,int>,int>>&vect,int k,vector<vector<int>>&dp){
        if(ind>=vect.size()||k<=0)return 0;
        // if(prev!=-1&& vect[ind].first.first <= vect[prev].first.second ) 
        //       return maxEvents( ind + 1 ,prev,vect,k,dp );
        
        if(dp[ind][k]!=-1)return dp[ind][k];
        
        // int take=0,ntake=0;
        // if(prev==-1||vect[prev].first.second<vect[ind].first.first){
        //     take=vect[ind].second+maxEvents(ind+1,ind,vect,k-1,dp);
        // }
        // ntake=0+maxEvents(ind+1,prev,vect,k,dp);
        
        int find=findSearch(ind+1,vect,vect[ind].first.second);
        
        
        return dp[ind][k]=max(maxEvents(ind+1,vect,k,dp),vect[ind].second+maxEvents(find,vect,k-1,dp));
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