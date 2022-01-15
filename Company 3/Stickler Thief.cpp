class Solution
{
    public:
    int FindMaxSum(int a[], int n)
    {
       int dp[n];
       memset(dp,0,sizeof(dp));
       
       dp[0] = a[0];
       dp[1] = max(a[0],a[1]);
       dp[2] = a[0] + a[2];
       
       if(n <= 2)
            return dp[n-1];
        
        for(int i = 3;i<n;i++)
            dp[i] = a[i] + max(dp[i-2],dp[i-3]);
        
        int ans = max(dp[n-1],dp[n-2]);
        return ans;
            
    }
};