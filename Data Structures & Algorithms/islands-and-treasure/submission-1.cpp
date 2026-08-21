class Solution {
private:
vector<int>rr={0,1,0,-1};
vector<int>cc={-1,0,1,0};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf=2147483647;
        queue<pair<int,int>>q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+rr[i];
                int nc=c+cc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n
                && grid[nr][nc]==inf){
                    grid[nr][nc]=grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
