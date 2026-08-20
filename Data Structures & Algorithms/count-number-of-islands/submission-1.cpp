class Solution {
private:
    vector<int> row={0,1,0,-1};
    vector<int>col={-1,0,1,0};
    void dfs(int i,int j,vector<vector<bool>>&visited,
    vector<vector<char>>&grid){
        visited[i][j]=true;

        for(int k=0;k<4;k++){
            int nr=row[k]+i;
            int nc=col[k]+j;
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()&&
            grid[nr][nc]=='1'&& !visited[nr][nc]){
                dfs(nr,nc,visited,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        int count=0;
        for(int i=0;i<r;i++){
            for( int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,visited,grid);
                    count++;
                }
            }
        }

        return count;

    }
};
