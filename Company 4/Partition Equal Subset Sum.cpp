class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum+=arr[i];
        
        if(sum%2!=0)
            return 0;
        else
        {
            sum/=2;
            bool dp[n+1][sum+1];
            
            for(int i = 0;i<n+1;i++)
            {
                for(int j = 0;j<sum+1;j++)
                {
                    if(i == 0)
                        dp[i][j] = false;
                        
                    if(j == 0)
                        dp[i][j] = true;
                    
                    if(i!=0 && j!=0)
                    {
                        if(arr[i-1]>j)
                            dp[i][j] = dp[i-1][j];
                        else
                            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    }
                }
            }
            if(dp[n][sum] == false)
                return 0;
            else
                return 1;
        }
    }
};