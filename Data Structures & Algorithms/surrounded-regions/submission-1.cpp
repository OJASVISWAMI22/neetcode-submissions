class Solution {
private:
vector<int>nr={-1,0,1,0};
vector<int>nc={0,-1,0,1};
void dfs(int i,int j,vector<vector<char>>&board){
    board[i][j]='T';
    for(int k=0;k<4;k++){
        int r=i+nr[k];
        int c=j+nc[k];
        if(r>=0 && c>=0 && r<board.size() && c< board[0].size() && board[r][c]=='O'){
            dfs(r,c,board);
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
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='T'){
                    dfs(i,j,board);
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
