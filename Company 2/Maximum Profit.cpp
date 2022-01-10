class Solution {
  public:
    int maxProfit(int k, int n, int price[]) 
    {
        vector<vector<int>> dp(k+1,vector<int> (n,0));
        
        for(int i = 1;i<k+1;i++)
        {
            int uptoNm1 = INT_MIN;
            for(int j = 1;j<n;j++)
            {
                uptoNm1 = max(uptoNm1,(dp[i-1][j-1]-price[j-1]));
                dp[i][j] = max(dp[i][j-1],(uptoNm1+price[j]));
            }
        }
        return dp[k][n-1];
    }
};