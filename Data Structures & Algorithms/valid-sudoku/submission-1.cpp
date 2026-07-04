class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int>rows[9];
        unordered_set<int>cols[9];
        unordered_set<int>sub[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'0';
                int box=(i/3)*3+(j/3);
                if(rows[i].count(num) || cols[j].count(num)
                || sub[box].count(num)){
                    return false;
                }
                rows[i].insert(num);
                cols[j].insert(num);
                sub[box].insert(num);
            }
        }
        return true;
    }
};
