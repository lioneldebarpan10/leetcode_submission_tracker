class Solution {
    int directions[4][2] = {{-1 , 0} , {0 , -1} , {1 , 0} , {0 , 1}};
public:
    int numIslands(vector<vector<char>>& grid){
        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        int islands = 0;
        for(int i = 0 ; i < ROWS ; i++){
            for(int j = 0 ; j < COLS ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid , i , j);
                    islands++;
                }
            }
        }
        return islands;

    }
    void dfs(vector<vector<char>>& grid , int r , int c) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        for(int i = 0 ; i < 4 ; i++){
            dfs(grid,
                r + directions[i][0],
                c + directions[i][1]
            );
        }   
    }
};