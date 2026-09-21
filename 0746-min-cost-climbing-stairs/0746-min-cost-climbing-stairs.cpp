class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Step-1: Creating a dp array of size (n+1)
        vector<int> dp(n+1);
        // Step-2: Handling the Base Cases
        dp[0] = 0;
        dp[1] = 0;
        // Step-3: Build up the dp array
        for(int i = 2 ; i <= n ; i++){
            dp[i] = min(
                dp[i - 1] + cost[i - 1], // taking 1 step from (i - 1)
                dp[i - 2] + cost[i - 2]  // taking 2 step from (i - 2)
            );
        }
        // Step-4: return Minimum cost to reach at the top
        return dp[n];
    }
};