class Solution {
public:
    // Space Optimized Tabulation Method
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp(n , 0); // declaring 1-D Array for storing minimum sum
        dp[0] = grid[0][0];

        // filing rows
        for(int j = 1 ; j < n ; j++){
            dp[j] = dp[j-1] + grid[0][j];
        }
        // filing rest
        for(int i = 1 ; i < m ; i++){
            dp[0] += grid[i][0]; // update first column
            for(int j = 1 ; j < n ; j++){
                dp[j] = grid[i][j] + min(dp[j] , dp[j-1]);
            }
        }
        return dp[n-1]; // ans at the last element of the array    
    }
};