class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>row={0,1,0,-1};
        vector<int>col={-1,0,1,0};
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int maxtime=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int time=it.second;
            time+=1;
            for(int t=0;t<4;t++){
                int nr=it.first.first+row[t];
                int nc=it.first.second+col[t];
                if(nr>=0 && nc>=0 && nr<r && nc<c &&
                grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({{nr,nc},time});
                    maxtime=max(maxtime,time);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }

        return maxtime;
    }
};
