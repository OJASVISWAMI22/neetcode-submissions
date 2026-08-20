class Solution {
private:
vector<int>row={0,1,0,-1};
vector<int>col={-1,0,1,0};
int dfs(int i,int j,vector<vector<bool>>&visited,
vector<vector<int>>&grid,int &count){
    visited[i][j]=true;
    for(int t=0;t<4;t++){
        int nr=row[t]+i;
        int nc=col[t]+j;
        if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size()&&
        !visited[nr][nc] && grid[nr][nc]==1){
            count++;
            dfs(nr,nc,visited,grid,count);
        }
    }
    return count;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        int maxarea=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int temp=1;
                    int area=dfs(i,j,visited,grid,temp);
                    maxarea=max(maxarea,area);
                }
            }
        }
        return maxarea;
    }
};
