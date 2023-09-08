class Solution {
public:
   vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};
int minimumEffortPath(vector<vector<int>>& heights) {
int row=heights.size();
int col=heights[0].size();
 
   vector<vector<int>>visited(row, vector<int>(col ,1e9));
   priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
  
  q.push({0,{0,0}});
  // int diff=0;
  visited[0][0]=0;
  while(!q.empty()){
  int effort=q.top().first;
  int r=q.top().second.first;
  int c=q.top().second.second;
    q.pop();
    
    if(r==row-1&&c==col-1)return effort;
    for(auto it:dir){
      int nx=r+it.first;
      int ny=c+it.second;
      if(nx>=0&&nx<row && ny>=0&&ny<col){
        int newEffort=abs(heights[nx][ny]-heights[r][c]);
        newEffort=max(effort,newEffort);
          if(newEffort<visited[nx][ny]){
               q.push({newEffort,{nx,ny}});
               visited[nx][ny]=newEffort;
          }
       
      }
    }
  }


return 0;
   	 
}

};