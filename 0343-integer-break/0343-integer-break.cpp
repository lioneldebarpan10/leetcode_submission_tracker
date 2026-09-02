class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n + 1 , 0);

        for(int target = 2 ; target <= n ; target++){
            for(int i = 1 ; i < target ; i++){

                int option1 = i * (target - i);
                int option2 = i * dp[target - i];

                dp[target] = max(
                    dp[target],
                    max(option1 , option2)
                );
            }
        }
        return dp[n];
        
    }
};