class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<vector<int>>q;
        
        int total_keys=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@'){
                    q.push({i,j,0,0});
                }
                if(grid[i][j]>='a'&&grid[i][j]<='f'){
                    total_keys++;
                }
            }
        }
        vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
        int key_status=pow(2,total_keys)-1;
        int visited[n][m][key_status+1];
        memset(visited,0,sizeof(visited));
        
        while(!q.empty()){
            auto st=q.front();q.pop();
            int x=st[0],y=st[1],steps=st[2],current_status=st[3];
            
            if(current_status==key_status)return steps;
            
            for(auto it:dir){
                int nx=x+it.first;
                int ny=y+it.second;
                
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]!='#'&&!visited[nx][ny][current_status]){
                    
                    char ch=grid[nx][ny];
                    if(ch>='A'&&ch<='F'){
                        if((current_status>>(ch-'A'))&1==1){
                            visited[nx][ny][current_status]=1;
                            q.push({nx,ny,steps+1,current_status}); 
                        }
                                               
                    }
                    else if(ch>='a'&&ch<='f'){
                            int num= current_status|1<<(ch-'a');
                            visited[nx][ny][current_status]=1;
                            q.push({nx,ny,steps+1,num});
                    }
                    else{
                        visited[nx][ny][current_status]=1;
                        q.push({nx,ny,steps+1,current_status});
                    }
                }
            }
        }
        return -1;
        
    }
};