class Solution {
private:
    vector<int>nr={0,1,0,-1};
    vector<int>nc={-1,0,1,0};
    void dfs(int i,int j,vector<vector<int>>&visited,
    const vector<vector<int>>& grid,int& area){
        if(visited[i][j]){
            return ;
        }
        visited[i][j]=1;
        area++;
        for(int k=0;k<4;k++){
            int r=i+nr[k];
            int c=j+nc[k];
            if(r>=0 && r<grid.size()
            && c>=0 && c<grid[0].size() &&
            !visited[r][c] && grid[r][c]==1){
                dfs(r,c,visited,grid,area);
            }
        }
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxi=0;
        vector<vector<int>>visited(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int area=0;
                    dfs(i,j,visited,grid,area);
                    maxi=max(area,maxi);
                }
            }
        }
        return maxi;
    }
};
