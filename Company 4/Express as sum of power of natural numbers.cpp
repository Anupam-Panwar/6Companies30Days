class Solution{
    public:
    long long dp[1001][1001];
    long long getAllWaysHelper(int remainingSum, int power, int base)
    {
        long long result = pow(base, power);
          
        if(remainingSum == result)
            return 1;
        if(remainingSum < result)
            return 0;
        
        long long x;
        if(dp[remainingSum-result][base+1] == -1)
        {
            x = getAllWaysHelper(remainingSum - result, power, base + 1);
            dp[remainingSum-result][base+1] = x;
        }
        else
            x = dp[remainingSum-result][base+1];
    
        long long y;
        if(dp[remainingSum][base+1] == -1)
        {
            y = getAllWaysHelper(remainingSum, power, base + 1);
            dp[remainingSum][base+1] = y;
        }
        else
            y = dp[remainingSum][base+1];
        return x + y;
    }
    long long numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        return getAllWaysHelper(n,x,1);
    }
};