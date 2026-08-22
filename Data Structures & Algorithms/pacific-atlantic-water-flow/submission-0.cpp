class Solution {
    vector<int>row={0,1,0,-1};
    vector<int>col={-1,0,1,0};
bool dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>
&heights,bool& p,bool& a){
    int r=heights.size();
    int c=heights[0].size();
    if(i==0 || j==0){
        p=true;
    }
    if(i==r-1 || j==c-1){
        a=true;
    }
    if(p && a){
        return true;
    }
    visited[i][j]=true;
    for(int it=0;it<4;it++){
        int nr=i+row[it];
        int nc=j+col[it];
        if(nr < 0 || nr >= r || nc < 0 || nc >= c)
    continue;
        if(heights[nr][nc]<=heights[i][j] &&
        !visited[nr][nc]){
            dfs(nr,nc,visited,heights,p,a);
            if(p&&a){
                return true;
            }
        }
    }
    return p&&a;
}
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c= heights[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vector<vector<bool>>visited(r,vector<bool>(c,false));
                bool p=false;
                bool a=false;
                if(dfs(i,j,visited,heights,p,a)){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
