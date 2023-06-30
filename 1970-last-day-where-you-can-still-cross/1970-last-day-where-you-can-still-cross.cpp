class Solution {
public:
    vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
    
    bool isPossible(int day,vector<vector<int>>& cells,int n,int m){
      map<pair<int,int>,int>mp;
       for(int i=0;i<day;i++){
            mp[{cells[i][0]-1,cells[i][1]-1}]=1;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(mp[{0,i}]!=1){
                q.push({0,i});
                mp[{0,i}]=1;
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1)return true;
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[{nx,ny}]!=1){
                    q.push({nx,ny});
                    mp[{nx,ny}]=1;
                }
            }
        }
        return false;   
    }
    int latestDayToCross(int n, int m, vector<vector<int>>& cells) {
        int low=0, high=cells.size();
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(isPossible(mid,cells,n,m)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};