class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m+1 , vector<int>(n+1));

        //Base Case
        for(int i = 1 ; i <= m ; i++){
            dp[i][0] = i;
        }
        for(int j = 1 ; j <= n ; j++){
            dp[0][j] = j;
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                // if characters are same
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1]; // no operations take place
                }
                else{
                    // find min of these 3 nums
                    dp[i][j] = 1 + min({dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};