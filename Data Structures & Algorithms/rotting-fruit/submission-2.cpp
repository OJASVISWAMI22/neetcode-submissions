class Solution {
    vector<int>rr={0,1,0,-1};
    vector<int>cc={-1,0,1,0};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        bool is_empty=false;
        if (q.empty()) {
    is_empty=true;
}
        while(!q.empty()){
            int s=q.size();
            while(s--){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;

            for(int i=0;i<4;i++){

                int nr=r+rr[i];
                int nc=c+cc[i];
                if(nc>=0 && nc<m &&  nr >=0 && nr<n &&
                grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                }
            }
            
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(ans==-1){
            return is_empty?0:-1;
        }
        return ans;
    }
};
