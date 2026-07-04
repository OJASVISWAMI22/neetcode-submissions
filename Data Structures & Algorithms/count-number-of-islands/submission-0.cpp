class Solution {
    void dfs(vector<vector<bool>>& visited,vector<vector<char>>&grid,
    int i,int j){
        if( i<0 || i>=grid.size())
        return;
        if(j<0 || j>=grid[0].size())
        return;
        if(visited[i][j] || grid[i][j]=='0')
        return;

        visited[i][j]=true;
        dfs(visited,grid,i+1,j);
        dfs(visited,grid,i,j+1);
        dfs(visited,grid,i,j-1);
        dfs(visited,grid,i-1,j);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int c=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(c,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(visited,grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
