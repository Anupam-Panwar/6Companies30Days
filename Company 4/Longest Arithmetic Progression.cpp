/* 
3 6 9 12
[[],[3:1],[6:1,3:2],[9:1,6:2,3:3]]
 */
class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) 
    {
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                int diff = a[i]-a[j];
                if(dp[j].count(diff) != 0)
                    dp[i][diff] = dp[j][diff]+1;
                else
                    dp[i][diff] = 1;
                
                ans = max(ans,dp[i][diff]);
            }
        }
        ans++;
        return ans;
    }
};