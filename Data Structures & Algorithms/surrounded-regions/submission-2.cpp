class Solution {
vector<int>row={0,1,0,-1};
vector<int>col={-1,0,1,0};
void dfs(int i,int j,vector<vector<char>>&board,
    vector<vector<bool>>&visited){
        visited[i][j]=true;
        board[i][j]='T';
        for(int it=0;it<4;it++){
            int nr=i+row[it];
            int nc=j+col[it];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]=='O' && !visited[nr][nc]){
                dfs(nr,nc,board,visited);
            }
        }
}
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=0;i<c;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,visited);
            }
            if(board[r-1][i]=='O'){
                dfs(r-1,i,board,visited);
            }
        }
        for(int i=0;i<r;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,visited);
            }
            if(board[i][c-1]=='O'){
                dfs(i,c-1,board,visited);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};
