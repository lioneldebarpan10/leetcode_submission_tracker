class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<char>row[9];
        unordered_set<char>col[9];
        unordered_set<char>submat[9];

        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){

                if(board[i][j] == '.'){
                    continue;
                }
                char val = board[i][j];

                int boxIdx = (i / 3) * 3 + (j / 3);

                if(row[i].count(val) || col[j].count(val) || submat[boxIdx].count(val)){
                    return false;
                }
                row[i].insert(val);
                col[j].insert(val);
                submat[boxIdx].insert(val);
            }
        }
        return true;
        
    }
};