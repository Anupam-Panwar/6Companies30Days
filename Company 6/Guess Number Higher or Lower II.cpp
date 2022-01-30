class Solution {
public:
    int getMoneyAmount(int n) 
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i)
        {
            dp[i][i] = 0;
            if (i + 1 <= n) 
                dp[i][i + 1] = i;
            if (i + 2 <= n) 
                dp[i][i + 2] = i + 1;
        }
        
        for (int d = 3; d <= n; ++d)
        {
            for (int i = 1; i<= n-d; ++i)
            {
                int j = i + d;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k<= j-1; ++k)
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
            }
        }
        return dp[1][n];

        
    }
};