class Solution {
    // directions => {down , up , right , left}
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int area = 0; // keep track of area

        for(int r = 0 ; r < ROWS ; r++){
            for(int c = 0 ; c < COLS ; c++){
                // if it is land then dfs and calculate it's area
                if(grid[r][c] == 1){
                    area = max(area , dfs(grid , r , c));
                }
            }
        }
        return area; // max area
    }
    // dfs to check all 4 directions
    int dfs(vector<vector<int>>& grid , int r , int c){
        // if it out of bounds or it is water then return 0
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0; // marked curr cell as 0 to mark it as visited
        int res = 1; // count current cell

        // explore all possible directions
        for(int i = 0 ; i < 4 ; i++){
            res += dfs(grid , r + directions[i][0] , c + directions[i][1]);
        }
        return res; // total area of island
    }
};