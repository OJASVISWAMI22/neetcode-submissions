class Solution {
private:
vector<int>nr={-1,0,1,0};
vector<int>nc={0,-1,0,1};
void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&board){
    visited[i][j]=true;
    board[i][j]='T';
    for(int k=0;k<4;k++){
        int r=i+nr[k];
        int c=j+nc[k];
        if(r>=0 && c>=0 && r<board.size() && c< board[0].size() &&
        !visited[r][c] && board[r][c]=='O'){
            dfs(r,c,visited,board);
        }
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                board[0][i]='T';
            }
            if(board[m-1][i]=='O'){
                board[m-1][i]='T';
            }
        }

        for( int i=0;i<m;i++){
            if(board[i][0]=='O')
            board[i][0]='T';
            if(board[i][n-1]=='O')
            board[i][n-1]='T';
        }
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && board[i][j]=='T'){
                    dfs(i,j,visited,board);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }

    }
};
