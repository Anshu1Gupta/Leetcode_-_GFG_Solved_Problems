class Solution {
public:
        void bfs(int r,int c,vector<vector<int>>&visited,vector<vector<int>>& image,int newcolor,int old){
            queue<pair<int,int>>q;
            int n=image.size();
            int m=image[0].size();

            q.push({r,c});
            // visited[r][c]=1;
            vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
            while(!q.empty()){
                int row=q.front().first;
                int column=q.front().second;
                q.pop();
                for(auto it:dir){
                    int nr=row+it.first;
                    int nc=column+it.second;
                    if(nr>=0&&nr<n&&nc>=0&&nc<m&&visited[nr][nc]!=1&&image[nr][nc]==old){
                        image[nr][nc]=newcolor;
                           visited[nr][nc]=1;
                           q.push({nr,nc});
                    }
                }
            }

        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n=image.size();
        int m=image[0].size();
        int old=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>>visited(n,vector<int>(m,0));
        bfs(sr,sc,visited,image,color,old);
        return image;

    }
};