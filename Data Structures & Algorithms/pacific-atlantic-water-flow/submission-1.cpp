class Solution {
    vector<int>row={0,1,0,-1};
    vector<int>col={-1,0,1,0};
    void dfs(int i,int j,vector<vector<bool>>&visited,
        vector<vector<int>>&heights){
            int r=heights.size();
            int c=heights[0].size();
            visited[i][j]=true;
            
            for(int it=0;it<4;it++){
                int nr=i+row[it];
                int nc=j+col[it];
                if(nr < 0 || nr >= r || nc < 0 || nc >= c||
                visited[nr][nc])
                    continue;
                if(heights[nr][nc]>=heights[i][j] ){
                    dfs(nr,nc,visited,heights);
                }
            }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c= heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(r,vector<bool>(c,false));
        vector<vector<bool>>atlantic(r,vector<bool>(c,false));
        for(int i=0;i<c;i++){
            dfs(0,i,pacific,heights);
            dfs(r-1,i,atlantic,heights);
        }
        for(int j=0;j<r;j++){
            dfs(j,0,pacific,heights);
            dfs(j,c-1,atlantic,heights);
        }
        for(int i=0;i<r;i++){
            for( int j=0;j<c;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
