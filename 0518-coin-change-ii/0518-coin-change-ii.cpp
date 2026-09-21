class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long INF = (long long)INT_MAX;
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(INF, dp[i] + dp[i - coin]);
            }
        }
        return (int)dp[amount];
    }
};